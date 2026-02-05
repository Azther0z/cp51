// G A A

#include <bits/stdc++.h>
using namespace std;

char recur(int x, int n, int idx, vector<int>& g) {
	int l = idx;
	int mid = idx + g[n - 1];
	int r = idx + g[n - 1] + 3 + n;
	// cout << l << ' ' << mid << ' ' << r << endl;
	if (x == l || x == mid || x == r) {
		return 'g';
	}
	if (n == 0) {
		return 'a';
	}
	if (x < mid) {
		return recur(x, n - 1, l, g);
	}
	if (x < r) {
		return 'a';
	}
	return recur(x, n - 1, r, g);
}

int main() {
	int x;
	cin >> x;
	vector<int> g;
	g.push_back(3);
	for (int i = 1; g.back() < x; i++) {
		g.push_back(g.back() + 3 + i + g.back());
	}
	// for (auto s : g) {
	// 	cout << s << endl;
	// }
	// cout << g.size() << endl;
	cout << recur(x, g.size(), 1, g);
}
