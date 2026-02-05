// Linear Recurrence

#include <bits/stdc++.h>
using namespace std;

#define MOD 32717

int r(int n, int k, vector<int>& c, vector<int>& a, vector<int>& memo) {
	if (n < k) {
		return memo[n] = a[n];
	} else if (memo[n] != -1) {
		return memo[n];
	}
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += c[i] * r(n - i, k, c, a, memo);
		sum %= MOD;
	}
	return memo[n] = sum;
}

int main() {
	int k, n;
	cin >> k >> n;
	vector<int> c(k + 1);
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
	}
	vector<int> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	vector<int> memo(n + 1, -1);
	cout << r(n, k, c, a, memo);
}