// Eating Futomaki

#include <bits/stdc++.h>
using namespace std;

// R(l,r) = max{R(l+1,r-1)+max(a[l],a[r]),R(l+2,r-1)+max(a[l],a[l+1]),R(l,r-2)+max(a[r],a[r-1])}
int topDown(int l, int r, vector<int> &a, vector<vector<int>> &memo) {
	if (r - l + 1 < 2) {
		return 0;
	}
	if (memo[l][r] != -1) {
		return memo[l][r];
	}
	int result = topDown(l + 1, r - 1, a, memo) + max(a[l], a[r]);
	result = max(result, topDown(l + 2, r, a, memo) + max(a[l], a[l + 1]));
	result = max(result, topDown(l, r - 2, a, memo) + max(a[r], a[r - 1]));
	return memo[l][r] = result;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> memo(n, vector<int>(n, -1));
	cout << topDown(0, n - 1, a, memo);
}