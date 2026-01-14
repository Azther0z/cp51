// Wall Paint
// Hard

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vec(m);
	for (int i = 0; i < m + m; i++) {
		int x, c, d;
		cin >> x >> c >> d;
		c--;
		if (d == 0) {
			vec[c].first = x;
		} else if (d == 1) {
			vec[c].second = x;
		}
	}
	vector<int> pref(n + 2, 0);
	set<int> point;
	for (int i = 0; i < m; i++) {
		auto it = point.lower_bound(vec[i].first);
		if (it != point.end() && *it <= vec[i].second) {
			continue;
		}
		it = point.upper_bound(vec[i].second);
		if (it != point.begin()) {
			it--;
			if (*it >= vec[i].first) {
				continue;
			}
		}
		pref[vec[i].first]++;
		pref[vec[i].second + 1]--;
		point.insert(vec[i].first);
		point.insert(vec[i].second);
		// cout << vec[i].first << ' ' << vec[i].second << endl;
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		pref[i] += pref[i - 1];
		result = max(result, pref[i]);
	}
	cout << result;
}