// Sandworm

#include <bits/stdc++.h>
using namespace std;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

int main() {
	int r, c, k;
	cin >> r >> c >> k;
	vector<vector<int>> north(r + 1, vector<int>(c + 1));
	vector<vector<int>> south(r + 1, vector<int>(c + 1));
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> north[i][j];
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> south[i][j];
		}
	}
	while (k--) {
		int a, b;
		cin >> a >> b;
		if (!north[a][b] && !south[a][b]) {
			north[a][b] = 2;
		}
	}
	queue<pair<int, int>> que;
	vector<vector<bool>> visited(r + 1, vector<bool>(c + 1, false));
	que.push({1, 1});
	visited[1][1] = true;
	int result1 = 0;
	vector<pair<int, int>> worm;
	while (!que.empty()) {
		int ci = que.front().first;
		int cj = que.front().second;
		que.pop();
		if (north[ci][cj] == 2) {
			worm.push_back({ci, cj});
		}
		result1++;
		for (int dir = 0; dir < 4; dir++) {
			int ni = ci + di[dir];
			int nj = cj + dj[dir];
			if (1 <= ni && ni <= r && 1 <= nj && nj <= c && north[ni][nj] != 1 && !visited[ni][nj]) {
				que.push({ni, nj});
				visited[ni][nj] = true;
			}
		}
	}
	visited = vector<vector<bool>>(r + 1, vector<bool>(c + 1, false));
	int result2 = result1;
	for (pair<int, int> w : worm) {
		if (!visited[w.first][w.second]) {
			int count = 0;
			visited[w.first][w.second] = true;
			que.push(w);
			while (!que.empty()) {
				int ci = que.front().first;
				int cj = que.front().second;
				que.pop();
				count++;
				for (int dir = 0; dir < 4; dir++) {
					int ni = ci + di[dir];
					int nj = cj + dj[dir];
					if (1 <= ni && ni <= r && 1 <= nj && nj <= c && south[ni][nj] != 1 && !visited[ni][nj]) {
						que.push({ni, nj});
						visited[ni][nj] = true;
					}
				}
			}
			result2 = max(result2, result1 + count);
		}
	}
	cout << result2;
}