// Bigger Billboard

#include <bits/stdc++.h>
using namespace std;

// r(i) is maximum sum of chosen c at index i
// r(i) = max{r(i-1),r(i-2),r(i-3)+c[i]}

int r(int i, vector<int>& c, vector<int>& memo) {
	if (i < 0) {
		return 0;
	}
	if (memo[i] != -1) {
		return memo[i];
	}
	int result = max(r(i - 1, c, memo), r(i - 2, c, memo));
	result = max(result, r(i - 3, c, memo) + c[i]);
	return memo[i] = result;
}

int main() {
	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	vector<int> memo(n, -1);
	cout << r(n - 1, c, memo);
}