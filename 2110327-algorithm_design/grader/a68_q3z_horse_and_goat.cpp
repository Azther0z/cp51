// Horse and Goat
// Trick

#include <bits/stdc++.h>
using namespace std;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	pair<int, int> source, target;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'S') {
				source = {i, j};
			}
			if (grid[i][j] == 'T') {
				target = {i, j};
			}
		}
	}
	vector<vector<int>> distance(n, vector<int>(m, 1e9));
	// Keep track of minimum distance to reach a particular entire row or column using rocket
	vector<int> rowDistance(n, 1e9), colDistance(m, 1e9);
	distance[source.first][source.second] = 0;
	queue<pair<int, pair<int, int>>> que;
	que.push({0, source});
	while (!que.empty()) {
		int cd = que.front().first;
		int ci = que.front().second.first;
		int cj = que.front().second.second;
		que.pop();
		if (cd > distance[ci][cj]) {
			continue;
		}
		if (grid[ci][cj] == '#') {
			if (cd + 1 < rowDistance[ci]) {
				rowDistance[ci] = cd + 1;
				for (int nj = 0; nj < m; nj++) {
					if (cd + 1 < distance[ci][nj] && grid[ci][nj] != 'X') {
						distance[ci][nj] = cd + 1;
						que.push({cd + 1, {ci, nj}});
					}
				}
			}
			if (cd + 1 < colDistance[cj]) {
				colDistance[cj] = cd + 1;
				for (int ni = 0; ni < n; ni++) {
					if (cd + 1 < distance[ni][cj] && grid[ni][cj] != 'X') {
						distance[ni][cj] = cd + 1;
						que.push({cd + 1, {ni, cj}});
					}
				}

			}
		} else {
			for (int dir = 0; dir < 4; dir++) {
				int ni = ci + di[dir];
				int nj = cj + dj[dir];
				if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[ni][nj] != 'X' && cd + 1 < distance[ni][nj]) {
					distance[ni][nj] = cd + 1;
					que.push({cd + 1, {ni, nj}});
				}
			}
		}
	}
	cout << distance[target.first][target.second];
}