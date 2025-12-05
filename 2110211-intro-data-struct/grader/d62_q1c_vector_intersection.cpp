// Intersection

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<int> a, result;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.insert(x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (a.count(x)) {
			result.insert(x);
		}
	}
	for (auto x : result) {
		cout << x << ' ';
	}
}