// Important Roads

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  public:
	vector<int> parent;
	DisjointSet(int n) {
		parent.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
	}
	int find(int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = find(parent[x]);
	}
	void merge(int a, int b) {
		parent[find(a)] = parent[find(b)];
	}
};

class Edge {
  public:
	int a, b, w;
	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<Edge> edge(m);
	int sum = 0;
	DisjointSet dsu(n);
	for (int i = 0; i < m; i++) {
		cin >> edge[i].a >> edge[i].b >> edge[i].w;
		if (i < k) {
			sum += edge[i].w;
			dsu.merge(edge[i].a, edge[i].b);
		}
	}
	sort(edge.begin(), edge.end());
	for (Edge e : edge) {
		if (dsu.find(e.a) != dsu.find(e.b)) {
			sum += e.w;
			dsu.merge(e.a, e.b);
		}
	}
	cout << sum;
}