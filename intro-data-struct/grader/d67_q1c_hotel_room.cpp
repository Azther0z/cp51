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
				int amount = *it;
				ms.erase(ms.find(amount));
				int floor = *vec[amount].rbegin();
				result.push_back({floor, amount});
				vec[amount].erase(floor);
				p -= amount;
			} else {
				int amount = *it;
				ms.erase(ms.find(amount));
				int floor = *vec[amount].rbegin();
				result.push_back({floor, p});
				vec[amount].erase(floor);
				amount -= p;
				p = 0;
				if (amount > 0) {
					ms.insert(amount);
					vec[amount].insert(floor);
				}
			}
		}
		sort(result.begin(), result.end());
		for (auto r : result) {
			cout << r.first << ' ' << r.second << ' ';
		}
		cout << endl;
	}
}