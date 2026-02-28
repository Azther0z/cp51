// Multi Recurrence

#include <bits/stdc++.h>
using namespace std;

#define MOD 32717

int topDown(int n, int &k, vector<int> &a, vector<vector<int>> &b, vector<int> &memo) {
	if (n <= 0) {
		return 0;
	}
	if (n <= k) {
		return memo[n] = a[n] % MOD;
	}
	if (memo[n] != -1) {
		return memo[n];
	}
	int result = 0;
	for (int i : b[n]) {
		result = (result + topDown(n - i, k, a, b, memo)) % MOD;
	}
	return memo[n] = result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	vector<vector<int>> b(n + 1);
	for (int i = k + 1; i <= n; i++) {
		int p;
		cin >> p;
		while (p--) {
			int tmp;
			cin >> tmp;
			b[i].push_back(tmp);
		}
	}
	vector<int> memo(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		printf("%d ", topDown(i, k, a, b, memo));
	}
}