// Connected Component

#include <bits/stdc++.h>
using namespace std;

void dfs(int current, vector<vector<int>> &adjl, vector<bool> &visited) {
	visited[current] = true;
	for (int next : adjl[current]) {
		if (!visited[next]) {
			dfs(next, adjl, visited);
		}
	}
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjl(n + 1);
	while (e--) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	vector<bool> visited(n + 1, false);
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			result++;
			dfs(i, adjl, visited);
		}
	}
	cout << result;
}