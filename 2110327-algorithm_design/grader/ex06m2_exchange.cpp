// Exchange

#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int n;
	cin >> n;
	vector<vector<double>> adjm(n, vector<double>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adjm[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adjm[i][j] = max(adjm[i][j], adjm[i][k] * adjm[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (adjm[i][i] > 1) {
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << (solve() ? "YES\n" : "NO\n");
	}
}