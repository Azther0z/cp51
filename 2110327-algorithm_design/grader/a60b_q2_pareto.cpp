// Pareto Frontier

#include <bits/stdc++.h>
using namespace std;

vector<int> dnc(int l, int r, vector<pair<int, int>> &vec) {
	if (r - l == 1) {
		return {l};
	}
	int mid = l + (r - l) / 2;
	// after sort point based on x
	// it is guaranteed that left.x <= right.x
	vector<int> left = dnc(l, mid, vec);
	vector<int> right = dnc(mid, r, vec);
	vector<int> result(right);
	// we only need to compare with highest Y
	int maxRightY = 0;
	for (int r : right) {
		maxRightY = max(maxRightY, vec[r].second);
	}
	for (int l : left) {
		if (vec[l].second > maxRightY) {
			result.push_back(l);
		}
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}
	// sort point based on x
	sort(vec.begin(), vec.end());
	vector<int> result = dnc(0, n, vec);
	cout << result.size();
}