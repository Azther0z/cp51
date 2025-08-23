// Top Sales

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<pair<int, int>> st;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		mp[id] = 0;
	}
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int item, sales;
			cin >> item >> sales;
			if (mp.find(item) == mp.end()) {
				continue;
			}
			if (st.find({mp[item], item}) != st.end()) {
				st.erase({mp[item], item});
			}
			mp[item] += sales;
			st.insert({mp[item], item});
		}
		if (op == 2) {
			int k;
			cin >> k;
			auto it = st.lower_bound({k, 0});
			if (it == st.begin()) {
				cout << "NONE\n";
			} else {
				it--;
				cout << it->second << endl;
			}
		}
	}
}