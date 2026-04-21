// Path Sum

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> maxCost;
vector<vector<int>> adjm;

bool dfs(int current, int heuristic, int sum, vector<bool> &visited, int k) {
	if (sum == k) {
		return true;
	}
	if (sum > k) {
		return false;
	}
	if (sum + heuristic < k) {
		return false;
	}
	visited[current] = true;
	for (int next = 0; next < n; next++) {
		if (adjm[current][next] && !visited[next]) {
			if (dfs(next, heuristic - maxCost[next], sum + adjm[current][next], visited, k)) {
				return true;
			}
		}
	}
	visited[current] = false;
	return false;
}

int main() {
	cin >> n >> m;
	vector<int> k(8);
	for (int i = 0; i < 8; i++) {
		cin >> k[i];
	}
	adjm.resize(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adjm[a][b] = w;
		adjm[b][a] = w;
	}
	maxCost.resize(n, 0);
	int heuristic = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maxCost[i] = max(maxCost[i], adjm[i][j]);
		}
		heuristic += maxCost[i];
	}
	for (int x : k) {
		bool check = false;
		for (int start = 0; start < n; start++) {
			vector<bool> visited(n, 0);
			if (dfs(start, heuristic - maxCost[start], 0, visited, x)) {
				check = true;
				break;
			}
		}
		cout << (check ? "YES\n" : "NO\n");
	}
}