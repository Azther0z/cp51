// Restaurant

#include <bits/stdc++.h>
using namespace std;

long long binarySearch(long long x, int n, vector<int>& t) {
	if (x <= n) {
		return 0;
	}
	long long l = 0, r = 1e18;
	long long result = 1e18;
	while (l < r) {
		long long mid = l + (r - l) / 2;
		long long totalSeat = 0;
		for (int i = 0; i < n; i++) {
			totalSeat += (mid + t[i] - 1) / t[i];
		}
		if (totalSeat >= x) {
			result = min(result, mid);
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return max(0LL, result - 1);
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> t(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	while (q--) {
		long long x;
		cin >> x;
		cout << binarySearch(x, n, t) << endl;
	}
}