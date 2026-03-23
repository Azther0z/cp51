// Chokepoint
// Hard

#include <bits/stdc++.h>
using namespace std;

// chokepoint[i] = (n-1) + (n-size[i])*(size[i]-1) + combination of child
// n-1 is when we pair (i,every node)
// (n-size[i])*(size[i]-1) is when we pair (node that is not child,child node)
// combination of child is when we pair (child, other child)

void dfs(int current, int prev, vector<vector<int>> &adjl, vector<int> &sz, vector<long long> &result, int n) {
	result[current] = n - 1;
	for (int next : adjl[current]) {
		if (next != prev) {
			dfs(next, current, adjl, sz, result, n);
			result[current] += 1LL * sz[next] * (sz[current] - 1);
			sz[current] += sz[next];
		}
	}
	result[current] += 1LL * (n - sz[current]) * (sz[current] - 1);
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> adjl(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	vector<int> sz(n, 1);
	vector<long long> result(n, 0);
	dfs(0, -1, adjl, sz, result, n);
	for (long long r : result) {
		printf("%lld\n", r);
	}
}