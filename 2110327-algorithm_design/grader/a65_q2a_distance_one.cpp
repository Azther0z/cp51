// Bit String with 1's far apart

#include <bits/stdc++.h>
using namespace std;

#define MOD 100000007

// R(n,0) = R(n-1,0)+R(n-1,1)
// R(n,1) = R(n-k,0)+R(n-k,1)

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> memo(n + 1, vector<int>(2, 0));
	memo[1][0] = memo[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		memo[i][0] = (memo[i - 1][0] + memo[i - 1][1]) % MOD;
		memo[i][1] = (i - k > 0 ? (memo[i - k][0] + memo[i - k][1]) % MOD : 1);
	}
	cout << (memo[n][0] + memo[n][1]) % MOD;
}