// Mass Relay

#include <bits/stdc++.h>
using namespace std;

class Edge {
  public:
	int a, b, w;
	Edge() {}
	Edge(int na, int nb, int nw) {
		a = na, b = nb, w = nw;
	}
	bool operator<(const Edge other)const {
		return w < other.w;
	}
};

class DisjointSet {
  public:
	vector<int> root;
	DisjointSet(int n) {
		root.assign(n, 0);
		for (int i = 0; i < n; i++) {
			root[i] = i;
		}
	}
	int find(int a) {
		if (root[a] == a) {
			return a;
		}
		return root[a] = find(root[a]);
	}
	void merge(int a, int b) {
		root[find(a)] = find(b);
	}
};

vector<Edge> kruskal(vector<Edge> &edge, int n) {
	vector<Edge> result;
	sort(edge.begin(), edge.end());
	DisjointSet dsu(n);
	for (Edge e : edge) {
		if (dsu.find(e.a) != dsu.find(e.b)) {
			dsu.merge(e.a, e.b);
			result.push_back(e);
		}
	}
	return result;
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<Edge> edge(m);
	for (int i = 0; i < m; i++) {
		cin >> edge[i].a >> edge[i].b >> edge[i].w;
	}
	vector<Edge> mst = kruskal(edge, n);
	while (q--) {
		int d;
		cin >> d;
		cout << mst[mst.size() - d].w << endl;
	}
}