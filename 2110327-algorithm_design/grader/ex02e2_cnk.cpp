// Binomial Coefficient

#include <bits/stdc++.h>
using namespace std;

int cnk(int n, int k, vector<vector<int>>& memo) {
	if (n == k || k == 0) {
		return memo[n][k] = 1;
	}
	if (memo[n][k] != -1) {
		return memo[n][k];
	}
	return memo[n][k] = cnk(n - 1, k - 1, memo) + cnk(n - 1, k, memo);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
	cout << cnk(n, k, memo);
}