// Shortest Start

#include <bits/stdc++.h>
using namespace std;

class Edge {
  public:
	int a, b, w;
};

int main() {
	int n, m, k, target;
	cin >> n >> m >> k >> target;
	vector<int> start(k), minCost(n, 1e9);
	for (int i = 0; i < k; i++) {
		cin >> start[i];
		minCost[start[i]] = 0;
	}
	vector<Edge> edge(m);
	for (int i = 0; i < m; i++) {
		cin >> edge[i].a >> edge[i].b >> edge[i].w;
	}
	for (int i = 0; i < n - 1; i++) {
		for (Edge e : edge) {
			if (minCost[e.a] + e.w < minCost[e.b]) {
				minCost[e.b] = minCost[e.a] + e.w;
			}
		}
	}
	cout << minCost[target];
}