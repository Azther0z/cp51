// Diagonal Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));
	int result = -1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
			d[i][j] += d[i - 1][j - 1];
			for (int size = 1; size <= i && size <= j; size++) {
				result = max(result, d[i][j] - d[i - size][j - size]);
			}
		}
	}
	cout << result;
}