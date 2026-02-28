// Arch Match

#include <bits/stdc++.h>
using namespace std;

// f(l,r) = max{f(l+1,r-1)+a[l]*a[r],f(l,mid)+f(mid+1,r)}
int topDown(int l, int r, vector<int>& a, vector<vector<int>>& memo) {
	if (r <= l) {
		return memo[l][r] = 0;
	}
	if (memo[l][r] != -1) {
		return memo[l][r];
	}
	int result = a[l] * a[r] + topDown(l + 1, r - 1, a, memo);
	for (int mid = l; mid < r; mid++) {
		result = max(result, topDown(l, mid, a, memo) + topDown(mid + 1, r, a, memo));
	}
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