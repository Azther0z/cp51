// Detecting Cycle

#include <bits/stdc++.h>
using namespace std;

bool dfs(int current, int prev, vector<vector<int>> &adjl, vector<int> &visited) {
	visited[current] = 1;
	bool check = false;
	for (int next : adjl[current]) {
		if (next == prev) {
			continue;
		}
		if (visited[next] == 0) {
			check = max(check, dfs(next, current, adjl, visited));
		} else if (visited[next] == 2) {
			continue;
		} else if (visited[next] == 1) {
			check = true;
			continue;
		}
	}
	visited[current] = 2;
	return check;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, e;
		cin >> n >> e;
		vector<vector<int>> adjl(n);
		while (e--) {
			int a, b;
			cin >> a >> b;
			adjl[a].push_back(b);
			adjl[b].push_back(a);
		}
		vector<int> visited(n, 0);
		bool check = false;
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0) {
				if (dfs(i, -1, adjl, visited)) {
					check = true;
					break;
				}
			}
		}
		cout << (check ? "YES\n" : "NO\n");
	}
}