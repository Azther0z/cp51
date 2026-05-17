// Cross Province

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> adjl(2 * n);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adjl[a].push_back({b, w});
		adjl[b].push_back({a, w});
	}
	vector<long long> distance(2 * n, 1e18);
	distance[n] = 0;
	priority_queue<pair<long long, int>> pq;
	pq.push({0, n});
	while (!pq.empty()) {
		long long d = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (d > distance[current]) {
			continue;
		}
		for (pair<int, int> next : adjl[current]) {
			if (d + next.second < distance[next.first]) {
				distance[next.first] = d + next.second;
				pq.push({ -(d + next.second), next.first});
			}
		}
	}
	while (k--) {
		int a, b;
		cin >> a >> b;
		cout << distance[a] + distance[b] << endl;
	}
}