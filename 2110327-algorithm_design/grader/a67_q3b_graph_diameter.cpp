// Graph Diameter

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjm(n + 1, vector<int>(n + 1, 1e9));
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adjm[a][b] = c;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (adjm[i][k] != 1e9 && adjm[k][j] != 1e9) {
					adjm[i][j] = min(adjm[i][j], adjm[i][k] + adjm[k][j]);
				}
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				result = max(result, adjm[i][j]);
			}
		}
	}
	cout << result;
}