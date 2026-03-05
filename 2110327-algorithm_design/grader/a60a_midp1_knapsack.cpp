// 0-1 Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

void recur(int i, int j, vector<int>& result, vector<int>& weight, vector<int>& value, vector<vector<int>>& memo) {
	if (i == 0 || j == 0) {
		return;
	}
	if (memo[i - 1][j] == memo[i][j]) {
		recur(i - 1, j, result, weight, value, memo);
		return;
	}
	if (memo[i - 1][j - weight[i]] + value[i] == memo[i][j]) {
		result.push_back(i);
		recur(i - 1, j - weight[i], result, weight, value, memo);
		return;
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> weight(n + 1), value(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
	}
	vector<vector<int>> memo(n + 1, vector<int>(m + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cin >> memo[i][j];
		}
	}
	vector<int> result;
	recur(n, m, result, weight, value, memo);
	cout << result.size() << endl;
	for (int r : result) {
		cout << r << ' ';
	}
}