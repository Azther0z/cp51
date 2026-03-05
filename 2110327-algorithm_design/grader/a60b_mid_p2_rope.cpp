// Rope

#include <bits/stdc++.h>
using namespace std;

// R(i) = max{R(i-a),R(i-b),R(i-c)}+1

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> memo(n + 1, -1e9);
	memo[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i >= a) {
			memo[i] = max(memo[i], memo[i - a]);
		}
		if (i >= b) {
			memo[i] = max(memo[i], memo[i - b]);
		}
		if (i >= c) {
			memo[i] = max(memo[i], memo[i - c]);
		}
		memo[i]++;
	}
	cout << memo[n];
}