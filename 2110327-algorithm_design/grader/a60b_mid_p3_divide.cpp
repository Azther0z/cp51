// Dividing Rock
// Hard

#include <bits/stdc++.h>
using namespace std;

#define MOD 1997

// By pen and paper
// the nth item can either be
// 1. new group => r(n-1,k-1)
// 2. a member of k existed groups => k*r(n-1,k)
// r(n,k) = r(n-1,k-1)+r(n-1,k)*k
int r(int n, int k, vector<vector<int>>& memo) {
	if (k > n) {
		return 0;
	}
	if (k == 1 || k == n) {
		return 1;
	}
	if (memo[n][k] != -1) {
		return memo[n][k];
	}
	return memo[n][k] = (r(n - 1, k - 1, memo) + r(n - 1, k, memo) * k) % MOD;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
	cout << r(n, k, memo);
}