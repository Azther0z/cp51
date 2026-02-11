// Merge Count

#include <bits/stdc++.h>
using namespace std;

void recur(int& k, int l, int r, vector<int>& vec) {
	if (r - l == 1) {
		return;
	}
	int mid = l + (r - l) / 2;
	if (k != 0) {
		swap(vec[mid - 1], vec[mid]);
		k -= 2;
		recur(k, l, mid, vec);
		recur(k, mid, r, vec);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		vec[i] = i + 1;
	}
	k--;
	recur(k, 0, n, vec);
	if (k == 0) {
		for (int i = 0; i < n; i++) {
			cout << vec[i] << ' ';
		}
	} else {
		cout << -1;
	}
}