// Shortest Path in Hex Map V2

#include <bits/stdc++.h>
using namespace std;

int di[] = {0, 0, -1, -1, 1, 1};
int dj[][6] = {{ -1, 1, -1, 0, -1, 0}, { -1, 1, 0, 1, 0, 1}};

class State {
  public:
	int i, j, d;
	State(int ni, int nj, int nd) {
		i = ni;
		j = nj;
		d = nd;
	}
	bool operator<(const State &other) const {
		return d > other.d;
	}
};

int main() {
	int r, c, si, sj, ei, ej;
	cin >> r >> c >> si >> sj >> ei >> ej;
	vector<vector<int>> grid(r + 1, vector<int>(c + 1)), distance(r + 1, vector<int>(c + 1, 1e9));
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> grid[i][j];
		}
	}
	priority_queue<State> pq;
	pq.push(State(si, sj, grid[si][sj]));
	distance[si][sj] = grid[si][sj];
	while (!pq.empty()) {
		int ci = pq.top().i;
		int cj = pq.top().j;
		int cd = pq.top().d;
		pq.pop();
		if (cd > distance[ci][cj]) {
			continue;
		}
		for (int dir = 0; dir < 6; dir++) {
			int ni = ci + di[dir];
			int nj = cj + dj[ci % 2][dir];
			if (1 <= ni && ni <= r && 1 <= nj && nj <= c && cd + grid[ni][nj] < distance[ni][nj]) {
				distance[ni][nj] = cd + grid[ni][nj];
				pq.push(State(ni, nj, distance[ni][nj]));
			}
		}
	}
	cout << distance[ei][ej];
}