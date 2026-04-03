// Shortest Path in Grid

#include <bits/stdc++.h>
using namespace std;

class State {
  public:
	int i, j, d;
	State(int ni, int nj, int nd) {
		i = ni;
		j = nj;
		d = nd;
	}
};

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

int main() {
	int r, c;
	cin >> r >> c;
	vector<string> grid(r);
	for (int i = 0; i < r; i++) {
		cin >> grid[i];
	}
	queue<State> que;
	que.push(State(0, 0, 0));
	vector<vector<int>> distance(r, vector<int>(c, 1e9));
	distance[0][0] = 0;
	while (!que.empty()) {
		State current = que.front();
		que.pop();
		if (current.d > distance[current.i][current.j]) {
			continue;
		}
		if (current.i == r - 1 && current.j == c - 1) {
			cout << current.d;
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ni = current.i + di[dir];
			int nj = current.j + dj[dir];
			if (0 <= ni && ni < r && 0 <= nj && nj < c && grid[ni][nj] != '#' && current.d + 1 < distance[ni][nj]) {
				distance[ni][nj] = current.d + 1;
				que.push(State(ni, nj, current.d + 1));
			}
		}
	}
	cout << -1;
}