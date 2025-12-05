// Heap Rank Scope

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int mn = 0, l = x, r = x;
	while (l < n) {
		mn += min(r - l + 1, n - l);
		l = 2 * l + 1;
		r = 2 * r + 2;
	}
	int mx = n;
	while (x != 0) {
		x = (x - 1) / 2;
		mx--;
	}
	cout << mn << ' ' << mx;
}