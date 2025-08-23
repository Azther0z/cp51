// CPU Reservation

#include <bits/stdc++.h>
using namespace std;

bool valid(set<pair<int, int>> &st, pair<int, int> &current) {
	auto it = st.lower_bound({current.first, 0});
	if (it == st.end()) {
		it--;
		return it->second < current.first;
	}
	if (current.second < it->first) {
		it--;
		return it->second < current.first;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	set<pair<int, int>> st;
	st.insert({0, 0});
	for (int i = 1; i <= n; i++) {
		pair<int, int> current;
		cin >> current.first >> current.second;
		if (valid(st, current)) {
			cout << i <<  ' ';
			st.insert(current);
		}
	}
}