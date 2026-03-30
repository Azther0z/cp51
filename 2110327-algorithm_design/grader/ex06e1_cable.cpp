// Cable Company

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> adjl(n);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int tmp;
			cin >> tmp;
			adjl[i].push_back({j, tmp});
			adjl[j].push_back({i, tmp});
		}
	}
	priority_queue<pair<int, int>> pq;
	pq.push({0, 0});
	vector<bool> visited(n, false);
	int result = 0;
	while (!pq.empty()) {
		int cd = -pq.top().first;
		int ci = pq.top().second;
		pq.pop();
		if (visited[ci]) {
			continue;
		}
		visited[ci] = true;
		result += cd;
		for (pair<int, int> next : adjl[ci]) {
			if (!visited[next.first]) {
				pq.push({ -next.second, next.first});
			}
		}
	}
	cout << result;
}