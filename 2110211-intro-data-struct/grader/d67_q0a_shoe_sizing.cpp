// Shoe Sizing

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	while (m--) {
		int q, result = 2e9;
		cin >> q;
		auto it = lower_bound(vec.begin(), vec.end(), q);
		if (it != vec.end()) {
			result = *it;
		}
		if (it != vec.begin()) {
			it--;
			if (q - *it < result - q) {
				result = *it;
			}
		}
		cout << result << ' ';
	}
}