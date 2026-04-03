// Barcode
// Hard

#include <bits/stdc++.h>
using namespace std;

// R(n,k,0) = sum{R(n-i,k-1,1)|1<=i<=m}
// R(n,k,1) = sum{R(n-i,k-1,0)|1<=i<=m}
// R(0,*,*) = 0
// R(1<=i<=m,0,1) = 1

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	m = min(n, m);
	vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
	for (int i = 1; i <= m; i++) {
		memo[i][0][1] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int a = 1; a <= m; a++) {
				memo[i][j][0] += memo[max(0, i - a)][j - 1][1];
				memo[i][j][1] += memo[max(0, i - a)][j - 1][0];
			}
		}
	}
	cout << memo[n][k][0] + memo[n][k][1];
}