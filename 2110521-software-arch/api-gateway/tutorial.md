# Tutorial 07: Microservice API Gateway using Kong

- **Date:** October 2022
- **Architecture:** Clients → API Gateway → Services
- **Demo:** Kong and Konga
- **Operating system in the tutorial:** Windows 10
- **Prerequisites:** Node.js, Docker, PostgreSQL, Kong, Konga, and Insomnia

> This is a text-focused transcription of the supplied PDF. Embedded screenshots are not reproduced here.

## Reference links

- Video: [Courseville tutorial video](https://www.mycourseville.com/?q=cvdlit/theatre/youtube/list/4867/0)
- Node.js source code for Step 2.2(f): [Courseville course material](https://www.mycourseville.com/?q=courseville/course/35365/view_content_node_1007324_material)

## Step 0: Install Node.js and Docker

### 0.1 Install Node.js

Node.js is used to create HTTP services for testing the API gateway.

1. Download Node.js from [nodejs.org](https://nodejs.org/en/download/).
2. Download and run the Windows MSI installer, such as `node-v14.18.0-x64.msi`, or use the latest LTS release.
3. Verify the installation in Command Prompt:

   ```powershell
   node -v
   npm -v
   ```

### 0.2 Install Docker Desktop

Docker provides the image and container management tools. Install Docker Desktop from the [Docker for Windows installation page](https://docs.docker.com/docker-for-windows/install/). During setup, enable Hyper-V or install the required Windows components for WSL 2.

Verify the installation:

```powershell
docker -v
```

The tutorial uses Docker from the command line.

## Step 1: Install PostgreSQL and Kong containers

### 1.1 Pull PostgreSQL 9.6

The tutorial specifies PostgreSQL version 9.6:

```sh
docker pull postgres:9.6
```

### 1.2 Pull Kong

```sh
docker pull kong
```

### 1.3 Create and configure the containers

#### a. Create a Docker network

This network lets Kong and PostgreSQL communicate by container name.

```sh
docker network create kong-net
```

Kong runs in a container, so `localhost` in a Kong service URL refers to the Kong container, not the computer running these Node.js services. On Linux, set the host-side gateway address for `kong-net` in the shell used for the commands below:

```sh
export KONG_HOST="$(docker network inspect kong-net --format '{{(index .IPAM.Config 0).Gateway}}')"
```

With Docker Desktop for Windows, use `host.docker.internal` as `KONG_HOST` (or substitute it directly in the service URLs below).

#### b. Start PostgreSQL

```sh
docker run -d --name kong-database --network=kong-net \
  -p 5432:5432 \
  -e "POSTGRES_USER=kong" \
  -e "POSTGRES_DB=kong" \
  -e "POSTGRES_PASSWORD=kong" \
  postgres:9.6
```

#### c. Bootstrap Kong's database migrations

```sh
docker run --rm --network=kong-net \
  -e "KONG_DATABASE=postgres" \
  -e "KONG_PG_HOST=kong-database" \
  -e "KONG_PG_PASSWORD=kong" \
  kong:latest kong migrations bootstrap
```

#### d. Start Kong

```sh
docker run -d --name kong --network=kong-net \
  -e "KONG_DATABASE=postgres" \
  -e "KONG_PG_HOST=kong-database" \
  -e "KONG_PG_PASSWORD=kong" \
  -e "KONG_PROXY_ACCESS_LOG=/dev/stdout" \
  -e "KONG_ADMIN_ACCESS_LOG=/dev/stdout" \
  -e "KONG_PROXY_ERROR_LOG=/dev/stderr" \
  -e "KONG_ADMIN_ERROR_LOG=/dev/stderr" \
  -e "KONG_ADMIN_LISTEN=0.0.0.0:8001, 0.0.0.0:8444 ssl" \
  -e "KONG_PROXY_LISTEN=0.0.0.0:8000, 0.0.0.0:9080 http2, 0.0.0.0:9081 http2 ssl" \
  -p 8000:8000 \
  -p 8443:8443 \
  -p 127.0.0.1:8001:8001 \
  -p 127.0.0.1:8444:8444 \
  -p 127.0.0.1:9080:9080 \
  -p 127.0.0.1:9081:9081 \
  kong
```

#### e. Check that Kong is running

```sh
curl -i http://localhost:8001/
```

#### f. Add a service

This example uses `SimpleHTTP/main1.js` from this repository as the upstream. Start the local services in Step 2.2(f) before testing this route. The PDF's remote `mockbin.org` target is replaced so the demo uses your local service.

```sh
curl -i -X POST --url http://localhost:8001/services/ \
  --data name=simple-http-1 \
  --data-urlencode "url=http://${KONG_HOST}:8081"
```

#### g. Add a route

```sh
curl -i -X POST --url http://localhost:8001/services/simple-http-1/routes \
  --data 'paths[]=/mock'
```

#### h. Verify the route

Open [http://localhost:8000/mock](http://localhost:8000/mock). Kong should return `Hello World from Service1`.

## Step 2: Install and configure Konga

### 2.1 Pull the Konga image

```sh
docker pull pantsel/konga
```

### 2.2 Create and run Konga

#### a. Prepare Konga's database

```sh
docker run --rm --network=kong-net pantsel/konga \
  -c prepare -a postgres \
  -u postgresql://kong:kong@kong-database:5432/konga
```

#### b. Run Konga

```sh
docker run -p 1337:1337 --network=kong-net \
  -e "DB_ADAPTER=postgres" \
  -e "DB_HOST=kong-database" \
  -e "DB_URI=postgresql://kong:kong@kong-database:5432/konga" \
  -e "KONGA_HOOK_TIMEOUT=120000" \
  -e "NODE_ENV=production" \
  --name konga \
  pantsel/konga
```

Keep the terminal running while Konga is in use.

#### c. Open Konga

Visit [http://localhost:1337](http://localhost:1337) in a browser.

#### d. Set up a Konga user

Create the Konga user through the web interface.

#### e. Connect Konga to Kong

Create a connection with:

- **Name:** `Connect1`
- **Kong Admin URL:** `http://kong:8001`

### 2.2(f) Start local services

Use the services already in this repository. Start each service in its own terminal from the `api-gateway` directory, and leave the terminals open:

| Service | Start command | Listen address |
| --- | --- | --- |
| HTTP service 1 | `node SimpleHTTP/main1.js` | `8081` |
| HTTP service 2 | `node SimpleHTTP/main2.js` | `8082` |
| REST service | `cd SimpleREST && npm ci && node app.js` | `3000` |
| gRPC server | `cd SimplegRPC/node && npm ci && node greeter_server.js` | `50051` |

Check the HTTP and REST services directly from the host:

```sh
curl http://localhost:8081/
curl http://localhost:8082/
curl http://localhost:3000/
curl 'http://localhost:3000/account?username=nraboy'
```

The gRPC client can be tested directly from `SimplegRPC/node` with `node greeter_client.js` while the gRPC server is running. To test it through Kong, use the command in Step 6.

- Test the HTTP and REST services in a browser.
- Install [Insomnia](https://insomnia.rest/download) to test the gRPC service.

## Steps 3–6: Add services and routes in Konga

The following examples use the Kong Admin API; the same values can be entered in Konga. They assume the `KONG_HOST` value from Step 1.3(a). Do not use `localhost` as the upstream host because the applications are running on the host while Kong is in a container.

### Step 3: SimpleHTTP service and route

The service `simple-http-1` and route `/mock` were created in Step 1.3(f–h), pointing to `SimpleHTTP/main1.js` on port `8081`.

### Step 4: SimpleHTTP load balancer

Create an upstream with a target for each HTTP server, then route `/balanced` to it:

```sh
curl -i -X POST http://localhost:8001/upstreams \
  --data name=simple-http-upstream

curl -i -X POST http://localhost:8001/upstreams/simple-http-upstream/targets \
  --data "target=${KONG_HOST}:8081"

curl -i -X POST http://localhost:8001/upstreams/simple-http-upstream/targets \
  --data "target=${KONG_HOST}:8082"

curl -i -X POST http://localhost:8001/services \
  --data name=simple-http-lb \
  --data protocol=http \
  --data host=simple-http-upstream \
  --data port=80

curl -i -X POST http://localhost:8001/services/simple-http-lb/routes \
  --data 'paths[]=/balanced'
```

Test the load-balanced route with `curl -i http://localhost:8000/balanced`. Responses should come from `Service1` or `Service2`.

### Step 5: SimpleREST service and route

Configure Kong to reach `SimpleREST/app.js` on port `3000`. The `/rest` route prefix is stripped, so `/rest/account` reaches the application's `/account` endpoint.

```sh
curl -i -X POST http://localhost:8001/services \
  --data name=simple-rest \
  --data-urlencode "url=http://${KONG_HOST}:3000"

curl -i -X POST http://localhost:8001/services/simple-rest/routes \
  --data 'paths[]=/rest'
```

Verify the route:

```sh
curl -i 'http://localhost:8000/rest/account?username=nraboy'
```

### Step 6: SimplegRPC service and route

`SimplegRPC/node/greeter_server.js` listens on port `50051`. Create a gRPC service and a route for the `SayHello` method:

```sh
curl -i -X POST http://localhost:8001/services \
  --data name=simple-grpc \
  --data protocol=grpc \
  --data host="$KONG_HOST" \
  --data port=50051

curl -i -X POST http://localhost:8001/services/simple-grpc/routes \
  --data 'paths[]=/helloworld.Greeter/SayHello' \
  --data 'protocols[]=grpc' \
  --data strip_path=false
```

The Kong container is configured with a cleartext HTTP/2 proxy listener on port `9080`. From `SimplegRPC/node`, call through Kong with:

```sh
node greeter_client.js --target=localhost:9080
```

## Step 7: Basic authentication

This example protects the `simple-rest` service created in Step 5. Requests to the service must go through Kong's proxy on port `8000`; calling port `3000` directly bypasses Kong and its authentication plugin.

### 7.1 Create a consumer and Basic Auth credential in Konga

1. Open [http://localhost:1337](http://localhost:1337), sign in to Konga, and select the `Connect1` connection.
2. In the left menu, open **Consumers** and click **Create Consumer**.
3. Set **Username** to `tutorial-user`. Leave **Custom ID** blank, then save the consumer.
4. Open the new consumer and go to **Credentials**. Select **Basic** (Basic Auth), then click **Create Credentials**.
5. Enter a credential username of `tutorial-user` and a test password of your choice. Save the credential. The credential must belong to the consumer created above; using the same username for both makes the association easy to identify.

### 7.2 Enable the Basic Auth plugin on the service

1. In Konga, open **Services** and select `simple-rest`.
2. Open the service's **Plugins** page and click **Add Plugin**.
3. Select **Basic Authentication** (`basic-auth`). Keep it enabled and leave the other settings at their defaults for this exercise, then save.
4. Confirm that `basic-auth` appears in the plugin list for `simple-rest`. Applying the plugin to this service protects its `/rest` route without affecting the other services.

### 7.3 Verify authentication

An unauthenticated request through Kong should be rejected with `401 Unauthorized`:

```sh
curl -i 'http://localhost:8000/rest/account?username=nraboy'
```

Send the username and password created in Konga. Replace the example password below with your test password; the request should return `200 OK` and the account JSON:

```sh
curl -i --user 'tutorial-user:replace-with-your-test-password' \
  'http://localhost:8000/rest/account?username=nraboy'
```

### If Konga cannot add the plugin

Konga's [compatibility notes](https://github.com/pantsel/konga#compatibility) state that Konga 0.14.x supports Kong 1.x only. This tutorial uses `kong:latest` (Kong 3.9.4 in the demonstrated environment), so Konga's UI may not work with this Kong version. Use these equivalent Kong Admin API calls if the UI operation fails:

```sh
curl -i -X POST http://localhost:8001/consumers/ \
  --data username=tutorial-user

curl -i -X POST http://localhost:8001/consumers/tutorial-user/basic-auth \
  --data username=tutorial-user \
  --data password='replace-with-your-test-password'

curl -i -X POST http://localhost:8001/services/simple-rest/plugins/ \
  --data name=basic-auth \
  --data config.hide_credentials=true
```

Then repeat the unauthenticated and authenticated requests in Step 7.3.

## Step 8: Key authentication

This example protects the `simple-http-1` service and its `/mock` route from Step 1. Keeping it separate from the Basic Auth-protected `simple-rest` service lets you test Key Auth by itself. If both authentication plugins are enabled on the same service, Kong requires both credentials by default.

### 8.1 Create a consumer and API-key credential in Konga

1. In Konga, select the `Connect1` connection and open **Consumers**.
2. Click **Create Consumer**, set **Username** to `key-tutorial-user`, leave **Custom ID** blank, and save.
3. Open that consumer's **Credentials** page, select **Key Auth** (or **Key**), and click **Create Credentials**.
4. Set the key to `tutorial-api-key-123` and save it. If Konga generates a key automatically, copy the generated value for the test request.

### 8.2 Enable the Key Auth plugin on `simple-http-1`

1. In Konga, open **Services** and select `simple-http-1`.
2. Open **Plugins** → **Add Plugin**, select **Key Authentication** (`key-auth`), and save it enabled.
3. Keep the default **Key Names** value `apikey`. Kong will accept the key in an `apikey` header or query parameter.
4. Confirm that `key-auth` appears in the plugin list for `simple-http-1`.

### 8.3 Verify Key Auth through Kong

An unauthenticated request should return `401 Unauthorized`:

```sh
curl -i http://localhost:8000/mock
```

Send the credential in the `apikey` header. Replace the example value if Konga generated a different key; the request should return `200 OK` and `Hello World from Service1`:

```sh
curl -i -H 'apikey: tutorial-api-key-123' \
  http://localhost:8000/mock
```

Requests to `http://localhost:8081/` go directly to the Node.js service and bypass Kong's Key Auth plugin.

### If Konga cannot add the plugin

See the Konga/Kong compatibility note in Step 7. If Konga's UI cannot save the configuration, use the Kong Admin API instead. Reuse an existing `key-tutorial-user` consumer if you already created it in Konga:

```sh
curl -i -X POST http://localhost:8001/consumers/ \
  --data username=key-tutorial-user

curl -i -X POST http://localhost:8001/consumers/key-tutorial-user/key-auth \
  --data key=tutorial-api-key-123

curl -i -X POST http://localhost:8001/services/simple-http-1/plugins/ \
  --data name=key-auth \
  --data 'config.key_names[]=apikey'
```

Then repeat the requests in Step 8.3.

## Assignment

Install and use Kong as an API gateway for the REST and gRPC services from the previous assignment. Capture screenshots showing the services and routes in use. To find the computer's IPv4 addresses on Linux, run:

```sh
ip -br -4 addr
```

Choose the address for the active network interface (not `lo` or a Docker bridge). On Windows, use:

```powershell
ipconfig
```

For a Node.js service running on the Docker host, use the `KONG_HOST` gateway address from Step 1.3(a) in Kong's upstream URL; `localhost` inside the Kong container points back to Kong itself.
