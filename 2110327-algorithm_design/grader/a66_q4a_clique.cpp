// Clique

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> power, prefix;
vector<vector<int>> adjm;
int result = 0;

bool valid(int current, vector<int> &selected) {
	for (int prev : selected) {
		if (!adjm[current][prev]) {
			return false;
		}
	}
	return true;
}

void dfs(int current, int sum, vector<int> &selected) {
	result = max(result, sum);
	if (current == n) {
		return;
	}
	if (current != 0 && sum + prefix[n - 1] - prefix[current - 1] < result) {
		return;
	}
	for (int i = current; i < n; i++) {
		if (valid(i, selected)) {
			selected.push_back(i);
			dfs(i + 1, sum + power[i], selected);
			selected.pop_back();
		}
	}
}

int main() {
	cin >> n;
	power.resize(n);
	prefix.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> power[i];
		prefix[i] = power[i];
		if (i != 0) {
			prefix[i] += prefix[i - 1];
		}
	}
	adjm.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adjm[i][j];
		}
	}
	vector<int> selected;
	dfs(0, 0, selected);
	cout << result;
}