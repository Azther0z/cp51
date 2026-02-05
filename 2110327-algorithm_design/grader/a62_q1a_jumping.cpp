// Jumping

#include <bits/stdc++.h>
using namespace std;

int recur(int n, vector<int>& memo, vector<int>& score) {
	if (n <= 1) {
		return score[1];
	}
	if (memo[n] != -2e9) {
		return memo[n];
	}
	int result = -2e9;
	result = max(result, recur(n - 1, memo, score));
	result = max(result, recur(n - 2, memo, score));
	result = max(result, recur(n - 3, memo, score));
	return memo[n] = result + score[n];
}

int main() {
	int n;
	cin >> n;
	vector<int> score(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> score[i];
	}
	vector<int> memo(n + 1, -2e9);
	cout << recur(n, memo, score);
}