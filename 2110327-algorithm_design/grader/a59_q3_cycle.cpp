// Cycle in Tree

#include <bits/stdc++.h>
using namespace std;

int dfs(int current, int prev, vector<vector<int>> &adjl, vector<int> &visited, vector<int> &stk) {
	visited[current] = 1;
	stk.push_back(current);
	int count = 0;
	for (int next : adjl[current]) {
		if (next != prev) {
			if (visited[next] == 0) {
				count = max(count, dfs(next, current, adjl, visited, stk));
			}
			if (visited[next] == 1) {
				count = 0;
				for (int i : stk) {
					if (i == next) {
						break;
					}
					count++;
				}
				count = stk.size() - count;
			}
			if (visited[next] == 2) {
				continue;
			}
		}
	}
	stk.pop_back();
	visited[current] = 2;
	return count;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> adjl(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	vector<int> visited(n, 0), stk;
	cout << dfs(0, -1, adjl, visited, stk);
}