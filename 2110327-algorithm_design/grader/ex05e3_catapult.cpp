// Catapult

#include <bits/stdc++.h>
using namespace std;

void dfs(int current, vector<vector<int>> &adjl, vector<bool> &visited, vector<int> &component) {
	visited[current] = true;
	for (int next : adjl[current]) {
		if (!visited[next]) {
			dfs(next, adjl, visited, component);
		}
	}
	component.push_back(current);
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> adjl(n), adjlReverse(n);
	for (int i = 0; i < n; i++) {
		int m, next;
		cin >> m;
		while (m--) {
			cin >> next;
			adjl[i].push_back(next);
			adjlReverse[next].push_back(i);
		}
	}
	vector<bool> visited(n, false);
	vector<int> order;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, adjl, visited, order);
		}
	}
	visited = vector<bool>(n, false);
	vector<int> result;
	for (int i = n - 1; i >= 0; i--) {
		int current = order[i];
		if (!visited[current]) {
			vector<int> component;
			dfs(current, adjlReverse, visited, component);
			result.push_back(component.size());
		}
	}
	sort(result.begin(), result.end());
	for (int r : result) {
		printf("%d ", r);
	}
}