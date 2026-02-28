// Stable Sort Check

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (m--) {
		vector<int> b(n + 1), c(n + 1);
		bool isSorted = true, isStable = true;
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
			c[i] = a[b[i]];
			if (i != 1) {
				if (c[i - 1] > c[i]) {
					isSorted = false;
				}
				if (c[i - 1] == c[i] && b[i - 1] > b[i]) {
					isStable = false;
				}
			}
		}
		printf("%d %d\n", isSorted, isSorted && isStable);
	}
}