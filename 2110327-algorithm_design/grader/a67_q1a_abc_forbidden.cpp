// ABC Permutation with Forbidden Pattern

#include <bits/stdc++.h>
using namespace std;

void permutation(string current, int i, int j, int k, int n, vector<string>& result, vector<string>& forbid) {
	if (current.size() >= 2) {
		for (string f : forbid) {
			if (current[current.size() - 2] == f[0] && current[current.size() - 1] == f[1]) {
				return;
			}
		}
	}
	if (current.size() == n) {
		result.push_back(current);
		return;
	}
	if (i > 0) {
		permutation(current + 'A', i - 1, j, k, n, result, forbid);
	}
	if (j > 0) {
		permutation(current + 'B', i, j - 1, k, n, result, forbid);
	}
	if (k > 0) {
		permutation(current + 'C', i, j, k - 1, n, result, forbid);
	}
}

int main() {
	int n, i, j, k, m;
	cin >> n >> i >> j >> k >> m;
	vector<string> forbid(m);
	for (int i = 0; i < m; i++) {
		cin >> forbid[i];
	}
	vector<string> result;
	permutation("", i, j, k, n, result, forbid);
	cout << result.size() << endl;
	for (string r : result) {
		cout << r << endl;
	}
}