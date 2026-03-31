// Shortest Path with Negative Edge

#include <bits/stdc++.h>
using namespace std;

class Edge {
  public:
	int a, b, w;
};

int main() {
	int n, e, s;
	cin >> n >> e >> s;
	vector<Edge> edge(e);
	for (int i = 0; i < e; i++) {
		cin >> edge[i].a >> edge[i].b >> edge[i].w;
	}
	vector<int> distance(n, 1e9);
	distance[s] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (Edge e : edge) {
			if (distance[e.a] + e.w < distance[e.b]) {
				distance[e.b] = distance[e.a] + e.w;
			}
		}
	}
	bool check = true;
	for (Edge e : edge) {
		if (distance[e.a] + e.w < distance[e.b]) {
			check = false;
		}
	}
	if (check) {
		for (int d : distance) {
			printf("%d ", d);
		}
	} else {
		cout << -1;
	}
}