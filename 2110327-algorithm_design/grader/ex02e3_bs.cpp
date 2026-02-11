// Binary Search Repeat

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	while (m--) {
		int x;
		cin >> x;
		auto it = upper_bound(vec.begin(), vec.end(), x);
		cout << (it == vec.begin() ? -1 : it - vec.begin() - 1) << endl;
	}
}