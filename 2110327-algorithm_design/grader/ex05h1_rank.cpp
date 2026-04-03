// Game Ranking

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
	int n, p;
	cin >> n >> p;
	vector<vector<int>> adjl(n), adjlReverse(n);
	while (p--) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjlReverse[b].push_back(a);
	}
	// Kosaraju's
	vector<bool> visited(n, false);
	vector<int> order;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, adjl, visited, order);
		}
	}
	visited = vector<bool>(n, false);
	vector<int> group(n);
	int groupIdx = 0;
	for (int i = n - 1; i >= 0; i--) {
		int current = order[i];
		if (!visited[current]) {
			vector<int> component;
			dfs(current, adjlReverse, visited, component);
			for (int c : component) {
				group[c] = groupIdx;
			}
			groupIdx++;
		}
	}
	// Create condensation graph and topological sort
	vector<vector<int>> adjlGroup(groupIdx);
	vector<int> inDeg(groupIdx, 0);
	for (int i = 0; i < n; i++) {
		for (int next : adjl[i]) {
			if (group[i] != group[next]) {
				adjlGroup[group[i]].push_back(group[next]);
				inDeg[group[next]]++;
			}
		}
	}
	queue<pair<int, int>> que;
	for (int i = 0; i < groupIdx; i++) {
		if (inDeg[i] == 0) {
			que.push({i, 1});
		}
	}
	vector<int> rank(groupIdx);
	int maxRank = 1;
	while (!que.empty()) {
		int current = que.front().first;
		int r = que.front().second;
		que.pop();
		rank[current] = r;
		maxRank = max(maxRank, r);
		for (int next : adjlGroup[current]) {
			inDeg[next]--;
			if (inDeg[next] == 0) {
				que.push({next, r + 1});
			}
		}
	}
	vector<int> result(maxRank + 1, 0);
	for (int i = 0; i < n; i++) {
		result[rank[group[i]]]++;
	}
	for (int i = 1; i <= maxRank; i++) {
		printf("%d ", result[i]);
	}
}