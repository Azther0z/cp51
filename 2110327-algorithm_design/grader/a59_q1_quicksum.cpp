// Quick Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> p(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> p[i][j];
			p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
		}
	}
	while (k--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1++;
		r2++;
		c1++;
		c2++;
		cout << p[r2][c2] - p[r1 - 1][c2] - p[r2][c1 - 1] + p[r1 - 1][c1 - 1] << endl;
	}
}