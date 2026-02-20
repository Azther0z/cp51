// AVL Distance
// Hard

#include <bits/stdc++.h>
using namespace std;

// First, count d[i][j] which represent number of path length j that end at i and not including path from its parent
void precompute(int current, int prev, vector<vector<int>>& d, vector<vector<int>>& adjl, int k) {
	d[current][0] = 1;
	for (int next : adjl[current]) {
		if (next == prev) {
			continue;
		}
		precompute(next, current, d, adjl, k);
		d[current][1]++;
		for (int i = 2; i <= k; i++) {
			d[current][i] += d[next][i - 1];
		}
	}
}

// Second, at each node i, we calculate number of path length k that include i in its path by splitting length k to left child and right child
int compute(int current, int prev, vector<vector<int>>& d, vector<vector<int>>& adjl, int k) {
	int result = 0;
	vector<int> child;
	for (int next : adjl[current]) {
		if (next == prev) {
			continue;
		}
		result += compute(next, current, d, adjl, k);
		child.push_back(next);
	}
	if (child.size() == 1) {
		result += d[child[0]][k - 1];
	}
	if (child.size() == 2) {
		for (int i = 1; i <= k - 1; i++) {
			result += d[child[0]][i - 1] * d[child[1]][k - i - 1];
		}
		result += d[child[0]][k - 1];
		result += d[child[1]][k - 1];
	}
	return result;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adjl(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	vector<vector<int>> d(n + 1, vector<int>(501, 0));
	precompute(1, 0, d, adjl, k);
	cout << compute(1, 0, d, adjl, k);
}