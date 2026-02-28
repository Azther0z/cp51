// Farthest City

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> adjm(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adjm[i][j];
		}
	}
	priority_queue<pair<int, int>> pq;
	vector<int> dist(n, 1e9);
	pq.push({0, 0});
	while (!pq.empty()) {
		int current = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (d > dist[current]) {
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (adjm[current][i] != -1 && d + adjm[current][i] < dist[i]) {
				pq.push({d + adjm[current][i], i});
				dist[i] = d + adjm[current][i];
			}
		}
	}
	int result = 0;
	for (int i = 1; i < n; i++) {
		if (dist[i] == 1e9) {
			cout << -1;
			return 0;
		}
		result = max(result, dist[i]);
	}
	cout << result;
}