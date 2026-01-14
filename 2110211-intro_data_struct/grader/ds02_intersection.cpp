// Intersection

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int l = 0, r = 0;
	while (l < n && r < m) {
		if (a[l] < b[r]) {
			l++;
		} else if (a[l] > b[r]) {
			r++;
		} else if (a[l] == b[r]) {
			cout << a[l] << ' ';
			int tmp = a[l];
			while (l < n && r < m && a[l] == b[r] && a[l] == tmp) {
				l++;
				r++;
			}
		}
	}
}