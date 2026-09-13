# Simplified Tutor Matcher User API

This assignment-sized slice uses Tutor Matcher's `User` resource with only `id`, `name`, and `email`.

## Run

```bash
docker compose up --build
```

The API is available at `http://localhost:8001`, and PostgreSQL is exposed on port `5433`.

## Routes

| Method | Route        | Description    |
| ------ | ------------ | -------------- |
| GET    | `/users`     | Get all users  |
| GET    | `/users/:id` | Get one user   |
| POST   | `/users`     | Create a user  |
| PUT    | `/users/:id` | Replace a user |
| DELETE | `/users/:id` | Delete a user  |

POST and PUT use this JSON body:

```json
{
  "name": "Alice",
  "email": "alice@example.com"
}
```

## Postman

Import `Tutor-Matcher-User-API.postman_collection.json` into Postman, then run its requests from top to bottom. The POST request automatically saves the created user ID for GET ONE, PUT, and DELETE.
