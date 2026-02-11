// Modulo Exponent

#include <bits/stdc++.h>
using namespace std;

long long recur(int x, int n, int k, map<int, int>& memo) {
	if (n == 1) {
		return x % k;
	}
	if (memo.count(n)) {
		return memo[n] % k;
	}
	long long a = recur(x, n / 2, k, memo);
	if (n % 2 == 0) {
		return memo[n] = (a * a) % k;
	}
	long long b = recur(x, (n + 1) / 2, k, memo);
	return memo[n] = (a * b) % k;
}

int main() {
	// x^n % k
	int x, n, k;
	cin >> x >> n >> k;
	map<int, int> memo;
	cout << recur(x, n, k, memo);
}