// Increasing Sequence Sum

#include <bits/stdc++.h>
using namespace std;

void dfs(int back, int sum, int n, int &result) {
	if (sum == n) {
		result++;
		return;
	}
	for (int i = back; sum + i <= n; i++) {
		dfs(i, sum + i, n, result);
	}
}

int main() {
	int n;
	cin >> n;
	int result = 0;
	dfs(1, 0, n, result);
	cout << result;
}