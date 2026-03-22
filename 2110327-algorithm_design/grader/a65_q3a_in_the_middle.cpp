// In the Middle

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &adjl, int start, int n) {
	vector<int> distance(n + 1, 1e9);
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	distance[start] = 0;
	while (!pq.empty()) {
		int cd = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (cd > distance[current]) {
			continue;
		}
		for (int next : adjl[current]) {
			if (cd + 1 < distance[next]) {
				distance[next] = cd + 1;
				pq.push({ -(cd + 1), next});
			}
		}
	}
	return distance;
}

int main() {
	int n, t1, t2, t3;
	cin >> n >> t1 >> t2 >> t3;
	vector<vector<int>> adjl(n + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int tmp;
			cin >> tmp;
			adjl[i].push_back(tmp);
		}
	}
	vector<int> d1, d2, d3;
	d1 = dijkstra(adjl, t1, n);
	d2 = dijkstra(adjl, t2, n);
	d3 = dijkstra(adjl, t3, n);
	int result = 1e9;
	for (int i = 1; i <= n; i++) {
		result = min(result, max(max(d1[i], d2[i]), d3[i]));
	}
	cout << result;
}