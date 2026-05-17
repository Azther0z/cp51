// Weight Change

#include <bits/stdc++.h>
using namespace std;

class Edge {
  public:
	int a, b, w;
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<Edge> edge(m);
	for (int i = 0; i < m; i++) {
		cin >> edge[i].a >> edge[i].b >> edge[i].w;
	}
	vector<int> distance(n + 1, 1e9);
	Edge target = edge.back();
	edge.pop_back();
	distance[target.b] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (Edge e : edge) {
			if (distance[e.b] > distance[e.a] + e.w) {
				distance[e.b] = distance[e.a] + e.w;
			}
		}
	}
	if (distance[target.a] > 1e8) {
		cout << "-inf";
	} else {
		cout << -distance[target.a];
	}
}