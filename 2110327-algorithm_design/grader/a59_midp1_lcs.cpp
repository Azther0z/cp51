// Longest Commen Subsequence

#include <bits/stdc++.h>
using namespace std;

void recur(int n, int m, string& result, string& a, string& b, vector<vector<int>>& memo) {
	// printf("%d %d %c %c %d\n", n, m, a[n - 1], b[m - 1], memo[n][m]);
	if (n <= 0 || m <= 0) {
		return;
	}
	if (a[n - 1] == b[m - 1]) {
		result += a[n - 1];
		recur(n - 1, m - 1, result, a, b, memo);
		return;
	}
	if (memo[n - 1][m - 1] == memo[n][m]) {
		recur(n - 1, m - 1, result, a, b, memo);
		return;
	}
	if (memo[n - 1][m] == memo[n][m]) {
		recur(n - 1, m, result, a, b, memo);
		return;
	}
	recur(n, m - 1, result, a, b, memo);
}

int main() {
	int n, m;
	string a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int>> memo(n + 1, vector<int>(m + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cin >> memo[i][j];
		}
	}
	string result = "";
	recur(n, m, result, a, b, memo);
	reverse(result.begin(), result.end());
	cout << result;
}