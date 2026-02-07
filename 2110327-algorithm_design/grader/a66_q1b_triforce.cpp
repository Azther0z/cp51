// Triforce

#include <bits/stdc++.h>
using namespace std;

int recur(int n, int r, int c, vector<vector<int>>& vec) {
	if (n == 1) {
		return vec[r][c];
	}
	int half = n >> 1;
	for (int i = r + half; i < r + n; i++) {
		for (int j = c + half; j < c + n; j++) {
			if (vec[i][j] != 0) {
				return 0;
			}
		}
	}
	int x1 = recur(half, r, c, vec);
	int x2 = recur(half, r, c + half, vec);
	int x3 = recur(half, r + half, c, vec);
	if (x1 == 0 || x2 == 0 || x3 == 0) {
		return 0;
	}
	for (int i = 1; i <= 3; i++) {
		if ((x1 == i) + (x2 == i) + (x3 == i) >= 2) {
			return i;
		}
	}
	return 0;
}
int main() {
	int t = 3;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> vec(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> vec[i][j];
			}
		}
		cout << recur(n, 0, 0, vec) << endl;
	}
}