// K-ary Heap Check

#include <bits/stdc++.h>
using namespace std;

bool check(int n, int k, vector<int>& vec) {
	for (int i = 1; i < n; i++) {
		if (vec[(i - 1) / k] <= vec[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		vector<int> vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec[i];
		}
		cout << (check(n, k, vec) ? "true\n" : "false\n");
	}
}