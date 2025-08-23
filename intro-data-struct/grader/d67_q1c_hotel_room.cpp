// Hotel Room
// Hard

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<set<int>> vec(1001);
	multiset<int> ms;
	int total = 0;
	for (int i = 1; i <= n; i++) {
		int r;
		cin >> r;
		vec[r].insert(i);
		ms.insert(r);
		total += r;
	}
	while (m--) {
		int p;
		cin >> p;
		if (total < p) {
			cout << "-1\n";
			continue;
		}
		total -= p;
		vector<pair<int, int>> result;
		while (p > 0) {
			auto it = ms.lower_bound(p);
			if (it == ms.end()) {
				it--;
			}
			if (*it >= p) {
				int floor = *vec[*it].rbegin();
				// cout << floor << ' ' << p << endl;
				result.push_back({floor, p});
				int tmp = *it;
				ms.erase(it);
				vec[tmp].erase(*vec[tmp].rbegin());
				tmp -= p;
				p = 0;
				ms.insert(tmp);
				vec[tmp].insert(floor);
			} else {
				int floor = *vec[*it].rbegin();
				// cout << floor << ' ' << *it << ' ';
				result.push_back({floor, *it});
				int tmp = *it;
				ms.erase(it);
				p -= tmp;
				vec[tmp].erase(*vec[tmp].rbegin());
			}
		}
		sort(result.begin(), result.end());
		for (auto r : result) {
			cout << r.first << ' ' << r.second << ' ';
		}
		cout << endl;
	}
}