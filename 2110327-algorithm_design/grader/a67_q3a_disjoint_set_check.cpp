// Disjoint Set Check

#include <bits/stdc++.h>
using namespace std;

int topoSort(vector<int> &g, vector<int> &inDeg, int n) {
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (inDeg[i] == 0) {
			que.push(i);
		}
	}
	vector<int> sz(n + 1, 1);
	int result = 1;
	while (!que.empty()) {
		int current = que.front();
		que.pop();
		result = max(result, sz[current]);
		int next = g[current];
		if (next != -1) {
			inDeg[next]--;
			if (inDeg[next] == 0) {
				que.push(next);
			}
			sz[next] += sz[current];
			sz[current] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (inDeg[i] != 0) {
			return -1;
		}
	}
	return result;
}

int main() {
	int n, q;
	cin >> n >> q;
	while (q--) {
		vector<int> g(n + 1), inDeg(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> g[i];
			if (g[i] != -1) {
				inDeg[g[i]]++;
			}
		}
		int result = topoSort(g, inDeg, n);
		if (result == -1) {
			printf("0 0\n");
		} else {
			printf("1 %d\n", result);
		}
	}
}