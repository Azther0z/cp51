// Tower Defense

#include <bits/stdc++.h>
using namespace std;

int bruteforce(int m, int k, int w, int current, vector<int>& monsterPosition, vector<int>& monsterHealth, vector<int>& towerPosition) {
	if (current == k) {
		int total = 0;
		for (int i = 0; i < m; i++) {
			total += max(monsterHealth[i], 0);
		}
		return total;
	}
	int total = 1e9;
	for (int i = 0; i < m; i++) {
		if (abs(monsterPosition[i] - towerPosition[current]) <= w) {
			monsterHealth[i]--;

		}
		total = min(total, bruteforce(m, k, w, current + 1, monsterPosition, monsterHealth, towerPosition));
		if (abs(monsterPosition[i] - towerPosition[current]) <= w) {
			monsterHealth[i]++;
		}
	}
	return total;
}

int main() {
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	vector<int> monsterPosition(m), monsterHealth(m), towerPosition(k);
	for (int i = 0; i < m; i++) {
		cin >> monsterPosition[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> monsterHealth[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> towerPosition[i];
	}
	cout << bruteforce(m, k, w, 0, monsterPosition, monsterHealth, towerPosition);
}