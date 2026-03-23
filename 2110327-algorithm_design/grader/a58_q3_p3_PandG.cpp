// Pacman and Ghost

#include <bits/stdc++.h>
using namespace std;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

class Entity {
  public:
	int t, i, j;
	Entity() {}
	Entity(int nt, int ni, int nj) {
		t = nt;
		i = ni;
		j = nj;
	}
	bool operator<(const Entity &other)const {
		return t > other.t;
	}
};

// First, let all ghosts explore the grid to
// find minimum time to reach every possible grid
vector<vector<int>> minimumTimeToOccupy(vector<Entity> &ghost, vector<vector<char>> &grid, int r, int c) {
	priority_queue<Entity> pq(ghost.begin(), ghost.end());
	vector<vector<int>> distance(r, vector<int>(c, 1e9));
	for (Entity g : ghost) {
		distance[g.i][g.j] = g.t;
	}
	while (!pq.empty()) {
		int ct = pq.top().t;
		int ci = pq.top().i;
		int cj = pq.top().j;
		pq.pop();
		if (ct > distance[ci][cj]) {
			continue;
		}
		for (int d = 0; d < 4; d++) {
			int ni = ci + di[d];
			int nj = cj + dj[d];
			if (0 <= ni && ni < r && 0 <= nj && nj < c && grid[ni][nj] == '.' && ct + 1 < distance[ni][nj]) {
				pq.push(Entity(ct + 1, ni, nj));
				distance[ni][nj] = ct + 1;
			}
		}
	}
	return distance;
}

// Second, if there is a grid that pacman can reach at target time
// and pacman reach there faster than ghosts, then pacman survives
bool bfs(vector<vector<int>> &distance, vector<vector<char>> &grid, int si, int sj, int t, int r, int c) {
	queue<Entity> que;
	que.push(Entity(0, si, sj));
	vector<vector<bool>> visited(r, vector<bool>(c, false));
	visited[si][sj] = true;
	while (!que.empty()) {
		int ct = que.front().t;
		int ci = que.front().i;
		int cj = que.front().j;
		que.pop();
		if (t < distance[ci][cj]) {
			return true;
		}
		for (int d = 0; d < 4; d++) {
			int ni = ci + di[d];
			int nj = cj + dj[d];
			if (0 <= ni && ni < r && 0 <= nj && nj < c && grid[ni][nj] == '.' && !visited[ni][nj] && ct + 1 < distance[ni][nj]) {
				que.push(Entity(ct + 1, ni, nj));
				visited[ni][nj] = true;
			}
		}
	}
	return false;
}

void solve() {
	int r, c, n, t, si, sj;
	cin >> r >> c >> n >> t >> si >> sj;
	vector<Entity> ghost(n);
	for (int i = 0; i < n; i++) {
		cin >> ghost[i].t >> ghost[i].i >> ghost[i].j;
	}
	vector<vector<char>> grid(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}
	vector<vector<int>> distance = minimumTimeToOccupy(ghost, grid, r, c);
	cout << (bfs(distance, grid, si, sj, t, r, c) ? "YES\n" : "NO\n");
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		solve();
	}
}