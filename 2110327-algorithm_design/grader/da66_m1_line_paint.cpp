// Line Paint

#include <bits/stdc++.h>
using namespace std;

class Interval {
  public:
	set<pair<int, int>> st;
	Interval() {
	}
	void insert(int l, int r) {
		auto it = st.upper_bound({l , 0});
		if (it != st.begin()) {
			it--;
			if (it->second + 1 >= l) {
				l = min(l, it->first);
				r = max(r, it->second);
				it = st.erase(it);
			} else {
				it++;
			}
		}
		while (it != st.end() && r + 1 >= it->first) {
			r = max(r, it->second);
			it = st.erase(it);
		}
		st.insert({l, r});
	}
	void display() {
		for (auto x : st) {
			cout << x.first << ' ' << x.second << ' ';
		}
	}
};

int main() {
	int n;
	cin >> n;
	Interval interval;
	while (n--) {
		int l, r;
		cin >> l >> r;
		interval.insert(l, r);
	}
	interval.display();
}