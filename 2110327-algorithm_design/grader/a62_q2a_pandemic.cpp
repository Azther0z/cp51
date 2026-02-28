// Pandemic

#include <bits/stdc++.h>
using namespace std;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

bool valid(int i, int j, int r, int c, vector<vector<int>>& a) {
	return 0 <= i && i < r && 0 <= j && j < c && a[i][j] != -2;
}

int main() {
	int r, c, t;
	cin >> r >> c >> t;
	vector<vector<int>> a(r, vector<int>(c));
	queue<pair<int, pair<int, int>>> que;
	int result = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				que.push({0, {i, j}});
				a[i][j] = -1;
			}
			if (a[i][j] == 2) {
				a[i][j] = -2;
			}
			if (a[i][j] == 0) {
				a[i][j] = -1;
			}
		}
	}
	while (!que.empty()) {
		int d = que.front().first;
		int ci = que.front().second.first;
		int cj = que.front().second.second;
		que.pop();
		if (a[ci][cj] != -1 || d > t) {
			continue;
		}
		if (d <= t) {
			result++;
		}
		a[ci][cj] = d;
		for (int dir = 0; dir < 4; dir++) {
			if (valid(ci + di[dir], cj + dj[dir], r, c, a) && d + 1 <= t) {
				que.push({d + 1, {ci + di[dir], cj + dj[dir]}});
			}
		}
	}
	cout << result;
}