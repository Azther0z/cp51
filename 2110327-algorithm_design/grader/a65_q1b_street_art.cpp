// Street Art

#include <bits/stdc++.h>
using namespace std;

// recur(a,b,c) = count(b,c) + max{recur(p1)+recur(p2),recur(p1)+recur(p3),recur(p2)+recur(p3)}
// problem statement guarantee that each recurrence (b,c) will not overlap with other
long long recur(long long a, long long b, long long c, vector<long long>& y) {
	long long result = upper_bound(y.begin(), y.end(), c) - lower_bound(y.begin(), y.end(), b);
	// any (b,c) with no people walk will not contribute to solution
	if (result == 0) {
		return result;
	}
	if (c - b + 1 >= 3) {
		long long u = (c - b + 1) / 3;
		long long v = (c - b + 2) / 3;
		long long p1 = recur(a + 1, b, b + u - 1, y);
		long long p2 = recur(a + 2, b + u, b + u + v - 1, y);
		long long p3 = recur(a + 3, b + u + v, c, y);
		result += max(max(p1 + p2, p1 + p3), p2 + p3);
	}
	return result;
}

int main() {
	long long w;
	int n;
	cin >> w >> n;
	vector<long long> y(n);
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	sort(y.begin(), y.end());
	cout << recur(0, 1, w, y);
}