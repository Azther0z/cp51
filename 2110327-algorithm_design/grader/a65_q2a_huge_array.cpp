// Huge Array

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}
	sort(vec.begin(), vec.end());
	vector<int> prefix(n, 0);
	prefix[0] = vec[0].second;
	for (int i = 1; i < n; i++) {
		prefix[i] = vec[i].second + prefix[i - 1];
	}
	while (q--) {
		int x;
		cin >> x;
		int index = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();
		cout << vec[index].first << endl;
	}
}