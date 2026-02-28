// Line Graph

#include <bits/stdc++.h>
using namespace std;

bool dfs(int current, vector<vector<int>> &adjl, vector<int> &visited) {
	visited[current] = 1;
	bool check = true;
	for (int next : adjl[current]) {
		if (visited[next] == 0) {
			check &= dfs(next, adjl, visited);
		} else if (visited[next] == 2) {
			check = false;
		}
	}
	visited[current] = 2;
	if (!check || adjl[current].size() > 2) {
		return false;
	}
	return true;
}

int main() {
	int v, e;
	cin >> v >> e;
	vector<vector<int>> adjl(v);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	int result = 0;
	vector<int> visited(v, 0);
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			result += dfs(i, adjl, visited);
		}
	}
	cout << result;
}