// Expressway

#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &adjl, vector<int> &distance) {
	priority_queue<pair<int, int>> pq;
	pq.push({0, 1});
	distance[1] = 0;
	while (!pq.empty()) {
		int cd = -pq.top().first;
		int ci = pq.top().second;
		pq.pop();
		for (pair<int, int> next : adjl[ci]) {
			if (cd + next.second < distance[next.first]) {
				distance[next.first] = cd + next.second;
				pq.push({ -(cd + next.second), next.first});
			}
		}
	}
}

int main() {
	int n, target, cost;
	cin >> n >> cost;
	vector<vector<pair<int, int>>> adjl(n + 1);
	adjl[1].push_back({2, cost});
	adjl[2].push_back({1, cost});
	for (int i = 3; i <= n ; i++) {
		int k;
		cin >> k;
		while (k--) {
			cin >> target >> cost;
			adjl[i].push_back({target, cost});
			adjl[target].push_back({i, cost});
		}
		vector<int> distance(n + 1, 1e9);
		dijkstra(adjl, distance);
		printf("%d ", distance[2]);
	}
}