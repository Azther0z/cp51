// Find Max in 2D Matrix

#include <bits/stdc++.h>
using namespace std;

bool invalid(int a, int b) {
	return a > b;
}

bool outside(int a, int b, int c) {
	return (a >= c && b >= c) || (a < 0 && b < 0);
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> vec(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}
	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--, c1--, r2--, c2--;
		if (invalid(r1, r2) || invalid(c1, c2)) {
			cout << "INVALID\n";
			continue;
		}
		if (outside(r1, r2, n) || outside(c1, c2, m)) {
			cout << "OUTSIDE\n";
			continue;
		}
		int mx = -1e9;
		for (int i = r1; i <= min(r2, n - 1); i++) {
			for (int j = c1; j <= min(c2, m - 1); j++) {
				mx = max(mx, vec[i][j]);
			}
		}
		cout << mx << '\n';
	}
}