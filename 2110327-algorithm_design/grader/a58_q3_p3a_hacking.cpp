// Hacking

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> start(k), cost(n), distance(n, 1e9);
	for (int i = 0; i < k; i++) {
		cin >> start[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	vector<vector<int>> adjl(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	priority_queue<pair<int, int>> pq;
	for (int s : start) {
		pq.push({ -cost[s], s});
		distance[s] = cost[s];
	}
	while (!pq.empty()) {
		int cd = -pq.top().first;
		int ci = pq.top().second;
		pq.pop();
		if (cd > distance[ci]) {
			continue;
		}
		for (int next : adjl[ci]) {
			if (cd + cost[next] < distance[next]) {
				distance[next] = cd + cost[next];
				pq.push({ -(cd + cost[next]), next});
			}
		}
	}
	int result = 0;
	for (int d : distance) {
		// printf("%d ", d);
		result = max(result, d);
	}
	cout << result;
}