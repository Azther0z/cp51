#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> source, target;
int ei, ej;
string result_move = "";

vector<vector<pair<int, int>>> parent_node;
vector<vector<int>> dist;

void bfs(int si, int sj, const vector<vector<bool>>& locked) {
	parent_node.assign(n, vector<pair<int, int>>(n, { -1, -1}));
	dist.assign(n, vector<int>(n, 1e9));
	queue<pair<int, int>> q;
	q.push({si, sj});
	dist[si][sj] = 0;
	int dr[] = { -1, 1, 0, 0};
	int dc[] = {0, 0, -1, 1};
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
				if (!locked[nr][nc] && dist[nr][nc] == 1e9) {
					dist[nr][nc] = dist[r][c] + 1;
					parent_node[nr][nc] = {r, c};
					q.push({nr, nc});
				}
			}
		}
	}
}

void move_empty_to(int target_r, int target_c, vector<vector<bool>>& locked) {
	// BFS to get path that empty space will follow
	bfs(ei, ej, locked);

	// Extract the path out of BFS graph
	vector<pair<int, int>> path;
	int curr_r = target_r, curr_c = target_c;
	while (curr_r != ei || curr_c != ej) {
		path.push_back({curr_r, curr_c});
		pair<int, int> p = parent_node[curr_r][curr_c];
		curr_r = p.first;
		curr_c = p.second;
	}
	reverse(path.begin(), path.end());

	// Actually performing moves
	for (auto p : path) {
		if (p.first == ei - 1) result_move += 'D';
		else if (p.first == ei + 1) result_move += 'U';
		else if (p.second == ej - 1) result_move += 'R';
		else if (p.second == ej + 1) result_move += 'L';
		swap(source[ei][ej], source[p.first][p.second]);
		ei = p.first;
		ej = p.second;
	}
}

void route_tile_to_target(int si, int sj, int dest_i, int dest_j, vector<vector<bool>>& locked) {
	// We try to move the source tile to target tile by moving empty space next to it and swap them

	// BFS to get path that source tile will follow
	bfs(si, sj, locked);

	// Extract the path out of BFS graph
	vector<pair<int, int>> path;
	int pi = dest_i, pj = dest_j;
	while (pi != si || pj != sj) {
		path.push_back({pi, pj});
		pair<int, int> p = parent_node[pi][pj];
		pi = p.first;
		pj = p.second;
	}
	reverse(path.begin(), path.end());

	// Actually performing moves
	int ti = si, tj = sj;
	for (auto p : path) {
		locked[ti][tj] = true;
		move_empty_to(p.first, p.second, locked);
		locked[ti][tj] = false;
		if (p.first == ti - 1) result_move += 'U';
		else if (p.first == ti + 1) result_move += 'D';
		else if (p.second == tj - 1) result_move += 'L';
		else if (p.second == tj + 1) result_move += 'R';
		swap(source[ei][ej], source[ti][tj]);
		ei = ti;
		ej = tj;
		ti = p.first;
		tj = p.second;
	}
}

pair<int, int> find_nearest_color(int color, vector<vector<bool>>& locked, int dest_i, int dest_j) {
	// BFS from empty to every other tiles
	bfs(ei, ej, locked);
	vector<vector<int>> empty_dist = dist;

	// BFS from destination to every other tiles
	bfs(dest_i, dest_j, locked);
	vector<vector<int>> tile_dist = dist;

	// Get tile that has least distance from empty and destination tile
	int best_cost = 2e9;
	pair<int, int> best_tile = { -1, -1};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (source[i][j] == color && !locked[i][j]) {
				if (empty_dist[i][j] != 1e9 && tile_dist[i][j] != 1e9) {
					// Bounding heuristic
					int cost = empty_dist[i][j] + n * tile_dist[i][j];
					if (cost < best_cost) {
						best_cost = cost;
						best_tile = {i, j};
					}
				}
			}
		}
	}
	return best_tile;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	source.resize(n, vector<int>(n));
	target.resize(n - 2, vector<int>(n - 2));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> source[i][j];
			if (source[i][j] == -1) {
				ei = i;
				ej = j;
			}
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < n - 2; j++) {
			cin >> target[i][j];
		}
	}
	vector<vector<bool>> locked(n, vector<bool>(n, false));
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= n - 2; j++) {
			if (source[i][j] == target[i - 1][j - 1]) {
				locked[i][j] = true;
				continue;
			}
			pair<int, int> source_pos = find_nearest_color(target[i - 1][j - 1], locked, i, j);
			route_tile_to_target(source_pos.first, source_pos.second, i, j, locked);
			locked[i][j] = true;
		}
	}
	cout << result_move << "S" << "\n";
	return 0;
}