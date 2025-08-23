// Line Monopoly
// Hard

#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	set<pair<int, int>> st;
	while (n--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			r++;
			auto it = st.upper_bound({l, -1});
			if (it != st.begin()) {
				it--;
				if (it->first <= l && l <= it->second) {
					l = min(l, it->first);
					r = max(r, it->second);
					it = st.erase(it);
				} else {
					it++;
				}
			}
			while (it != st.end() && it->first <= r) {
				r = max(r, it->second);
				it = st.erase(it);
			}
			st.insert({l, r});
		} else if (op == 2) {
			cout << st.size() << endl;
		}
	}
}