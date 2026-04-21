// N Queen

#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, vector<pair<int, int>> &placement) {
	for (pair<int, int> p : placement) {
		if (p.first == i || p.second == j) {
			return false;
		}
		if (abs(p.first - i) == abs(p.second - j)) {
			return false;
		}
	}
	return true;
}

void dfs(int ci, vector<pair<int, int>> &placement, int &result, int n) {
	if (placement.size() == n) {
		result++;
		return;
	}
	if (ci == n) {
		return;
	}
	for (int j = 0; j < n; j++) {
		if (valid(ci, j, placement)) {
			placement.push_back({ci, j});
			dfs(ci + 1, placement, result, n);
			placement.pop_back();
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> placement;
	int result = 0;
	dfs(0, placement, result, n);
	cout << result;
}