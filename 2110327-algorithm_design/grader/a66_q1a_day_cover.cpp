// Day Cover

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<bitset<1001>> worker(m);
	for (int i = 0; i < m; i++) {
		int j;
		cin >> j;
		while (j--) {
			int tmp;
			cin >> tmp;
			worker[i][tmp - 1] = 1;
		}
	}
	bitset<1001> required;
	for (int i = 0; i < n; i++) {
		required[i] = 1;
	}
	int result = 1e9;
	for (int state = 0; state < 1 << 20; state++) {
		bitset<1001> cover;
		for (int pick = 0; pick < m; pick++) {
			if ((1 << pick)&state) {
				cover |= worker[pick];
			}
		}
		if (cover == required) {
			result = min(result, __builtin_popcount(state));
		}
	}
	cout << result;
}