// Permutation with Constraint

#include <bits/stdc++.h>
using namespace std;

bool valid(vector<bool>& used, vector<pair<int, int>>& constraint) {
	for (auto c : constraint) {
		if (!used[c.first] && used[c.second]) {
			return false;
		}
	}
	return true;
}

void permutation(int n, vector<int>& current, vector<bool>& used, vector<pair<int, int>>& constraint) {
	if (!valid(used, constraint)) {
		return;
	}
	if (current.size() == n) {
		for (auto r : current) {
			cout << r << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			current.push_back(i);
			used[i] = true;
			permutation(n, current, used, constraint);
			current.pop_back();
			used[i] = false;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> constraint(m);
	for (int i = 0; i < m; i++) {
		cin >> constraint[i].first >> constraint[i].second;
	}
	vector<int> current;
	vector<bool> used(n, false);
	permutation(n, current, used, constraint);
}