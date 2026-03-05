// Walk in the Forest

#include <bits/stdc++.h>
using namespace std;

// r(i,j) = max{s[i][j]+r(i-1,j),s[i][j]+r(i,j-1),2*s[i][j]+r(i-1,j-1)}

int topDown(int i, int j, vector<vector<int>>& score, vector<vector<int>>& memo) {
	if (i == 0 && j == 0) {
		return memo[0][0] = score[0][0];
	}
	if (i < 0) {
		return -1e9;
	}
	if (j < 0) {
		return -1e9;
	}
	if (memo[i][j] != -1) {
		return memo[i][j];
	}
	memo[i][j] = max(score[i][j] + topDown(i - 1, j, score, memo), score[i][j] + topDown(i, j - 1, score, memo));
	return memo[i][j] = max(memo[i][j], 2 * score[i][j] + topDown(i - 1, j - 1, score, memo));
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> score(n, vector<int>(m, 0));
	vector<vector<int>> memo(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> score[i][j];
		}
	}
	cout << topDown(n - 1, m - 1, score, memo);
}