// 2 Side Billboard

#include <bits/stdc++.h>
using namespace std;

#define LEFT 0
#define RIGHT 1

// for case not limit k
// recur(n,l) = max{recur(n-1,l),recur(n-w-1,r)+left[n]}
// recur(n,r) = max{recur(n-1,r),recur(n-w-1,l)+right[n]}
// recur(0,l) = recur(0,r) = 0
int solve1(int n, int w, vector<int>& left, vector<int>& right) {
	vector<vector<int>> memo(n + 1, vector<int>(2, 0));
	for (int i = 1; i <= n; i++) {
		memo[i][LEFT] = max(memo[i - 1][LEFT], memo[max(0, i - w - 1)][RIGHT] + left[i]);
		memo[i][RIGHT] = max(memo[i - 1][RIGHT], memo[max(0, i - w - 1)][LEFT] + right[i]);
	}
	return max(memo[n][LEFT], memo[n][RIGHT]);
}

// for case with limit k
// recur(n,l,k) = max{recur(n-1,l,k),recur(n-w-1,r,k-1)+left[n]}
// recur(n,r,k) = max{recur(n-1,r,k),recur(n-w-1,l,k-1)+right[n]}
// recur(0,l,k) = recur(0,r,k) = recur(n,l,0) = recur(n,r,0) = 0
int solve2(int n, int w, int k, vector<int>& left, vector<int>& right) {
	vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			memo[i][LEFT][j] = max(memo[i - 1][LEFT][j], memo[max(0, i - w - 1)][RIGHT][j - 1] + left[i]);
			memo[i][RIGHT][j] = max(memo[i - 1][RIGHT][j], memo[max(0, i - w - 1)][LEFT][j - 1] + right[i]);
		}
	}
	return max(memo[n][LEFT][k], memo[n][RIGHT][k]);
}

int main() {
	int n, w, k;
	cin >> n >> w >> k;
	vector<int> left(n + 1), right(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> left[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> right[i];
	}
	if (n == k) {
		cout << solve1(n, w, left, right);
	} else {
		cout << solve2(n, w, k, left, right);
	}
}