// Car Brake

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	map<int, int> vt, tv;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}
	sort(vec.begin(), vec.end());
	vt[k] = 0;
	tv[0] = k;
	for (int i = 0; i < n; i++) {
		k = max(k - vec[i].second, 0);
		vt[k] = vec[i].first;
		tv[vec[i].first] = k;
		if (k == 0) {
			break;
		}
	}
	while (m--) {
		int op, x;
		cin >> op >> x;
		if (op == 1) {
			auto it = prev(tv.upper_bound(x));
			cout << it->second << endl;
		} else if (op == 2) {
			auto it = prev(vt.lower_bound(x));
			cout << it->second << endl;
		}
	}
}