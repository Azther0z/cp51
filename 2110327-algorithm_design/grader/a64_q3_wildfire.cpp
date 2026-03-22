// Wildfire

#include <bits/stdc++.h>
using namespace std;

int dfs(int current, vector<vector<int>> &adjl, vector<int> &b) {
	int beauty = b[current];
	b[current] = 0;
	for (int next : adjl[current]) {
		if (b[next] != 0) {
			beauty += dfs(next, adjl, b);
		}
	}
	return beauty;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> adjl(n);
	vector<int> b(n), query(k);
	int beauty = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		beauty += b[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> query[i];
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
	}
	for (int q : query) {
		if (b[q] != 0) {
			beauty -= dfs(q, adjl, b);
		}
		printf("%d ", beauty);
	}
}