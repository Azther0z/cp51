// Billboard Feng Shui

#include <bits/stdc++.h>
using namespace std;


int n, k;
vector<int> c, pattern, bottomUp;
int result = 0;

void dfs(int current, int sum, vector<bool> &select) {
	if (current >= k) {
		bool check = true;
		for (int i = 0; i < k; i++) {
			if (select[current - k + i] != pattern[i]) {
				check = false;
				break;
			}
		}
		if (check) {
			return;
		}
	}
	if (sum + bottomUp[current] < result) {
		return;
	}
	if (current == n) {
		result = max(result, sum);
		return;
	}
	if (current == 0 || select[current - 1] == 0) {
		select[current] = true;
		dfs(current + 1, sum + c[current], select);
		select[current] = false;
	}
	dfs(current + 1, sum, select);
}

int main() {
	cin >> n >> k;
	c.resize(n);
	pattern.resize(k);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> pattern[i];
	}
	bottomUp.resize(n, 0);
	bottomUp[n - 1] = c[n - 1];
	bottomUp[n - 2] = max(c[n - 2], c[n - 1]);
	for (int i = n - 3; i >= 0; i--) {
		bottomUp[i] = max(c[i] + bottomUp[i + 2], bottomUp[i + 1]);
	}
	vector<bool> select(n, false);
	dfs(0, 0, select);
	cout << result;
}