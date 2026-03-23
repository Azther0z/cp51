// Ikea

#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &adjl, int n) {
	vector<int> path(n);
	for (int i = 0; i < n; i++) {
		cin >> path[i];
	}
	vector<bool> visited(n + 1, false);
	for (int i = 0; i < n; i++) {
		for (int prev : adjl[path[i]]) {
			if (!visited[prev]) {
				return false;
			}
		}
		visited[path[i]] = true;
	}
	return true;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjl(n + 1);
	while (e--) {
		int a, b;
		cin >> a >> b;
		adjl[b].push_back(a);
	}
	int q = 5;
	while (q--) {
		cout << (check(adjl, n) ? "SUCCESS\n" : "FAIL\n");
	}
}