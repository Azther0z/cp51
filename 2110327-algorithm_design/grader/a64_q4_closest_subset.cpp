// Closest Subset

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> a, suffix;
int result = 1e9;

void dfs(int current, int size, int sum) {
	if (size == m) {
		result = min(result, abs(sum - k));
		return;
	}
	if (current == n) {
		return;
	}
	if (m - size > n - current) {
		return;
	}
	if ((sum + a[n - 1]) - k > result) {
		return;
	}
	if (k - (sum + suffix[current]) > result) {
		return;
	}
	dfs(current + 1, size + 1, sum + a[current]);
	dfs(current + 1, size, sum);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	a.resize(n);
	suffix.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	suffix[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suffix[i] = a[i] + suffix[i + 1];
	}
	dfs(0, 0, 0);
	cout << result;
}