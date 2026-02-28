// Jumping with Cost

#include <bits/stdc++.h>
using namespace std;

// R(i) = max{R(i-j)-b[j]+a[i|1<=j<=k}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1), b(k + 1), memo(n + 1, -1e9);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> b[i];
	}
	memo[1] = a[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k && i - j >= 1; j++) {
			memo[i] = max(memo[i], memo[i - j] + a[i] - b[j]);
		}
	}
	cout << memo[n];
}