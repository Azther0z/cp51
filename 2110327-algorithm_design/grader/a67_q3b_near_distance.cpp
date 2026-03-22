// Near Distance

#include <bits/stdc++.h>
using namespace std;

int di[] = {0, 0, 1, -1};
int dj[] = { -1, 1, 0, 0};

vector<vector<int>> bfs(pair<int, int> start, vector<vector<int>> &grid, int r, int c) {
	queue<pair<int, pair<int, int>>> que;
	vector<vector<int>> distance(r, vector<int>(c, 1e9));
	que.push({0, start});
	distance[start.first][start.second] = 0;
	while (!que.empty()) {
		int cd = que.front().first;
		int ci = que.front().second.first;
		int cj = que.front().second.second;
		que.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ni = ci + di[dir];
			int nj = cj + dj[dir];
			if (0 <= ni && ni < r && 0 <= nj && nj < c && grid[ni][nj] != 1 && cd + 1 < distance[ni][nj]) {
				distance[ni][nj] = cd + 1;
				que.push({cd + 1, {ni, nj}});
			}
		}
	}
	return distance;
}

bool check(int x, int y, vector<vector<vector<int>>> &distance, int k) {
	for (int i = 0; i < distance.size(); i++) {
		if (distance[i][x][y] == 1e9) {
			return false;
		}
		for (int j = i + 1; j < distance.size(); j++) {
			if (abs(distance[i][x][y] - distance[j][x][y]) > k) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int r, c, k;
	cin >> r >> c >> k;
	vector<pair<int, int>> source;
	vector<vector<int>> grid(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 2) {
				source.push_back({i, j});
			}
		}
	}
	vector<vector<vector<int>>> distance;
	for (pair<int, int> s : source) {
		distance.push_back(bfs(s, grid, r, c));
	}
	int result = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			result += check(i, j, distance, k);
		}
	}
	// for (vector<vector<int>> d : distance) {
	// 	for (int i = 0; i < r; i++) {
	// 		for (int j = 0; j < c; j++) {
	// 			printf("%d ", d[i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n");
	// }
	cout << result;
}