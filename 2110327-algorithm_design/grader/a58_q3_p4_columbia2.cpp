// Columbia with Elizabeth

#include <bits/stdc++.h>
using namespace std;

int di[] = {0, 0, 1, -1};
int dj[] = { -1, 1, 0, 0};
int dii[] = {0, -1, -2, -1, 0, 1, 2, 1, 0, 0, 1, -1};
int djj[] = {2, 1, 0, -1, -2, -1, 0, 1, -1, 1, 0, 0};

class State {
  public:
	int i, j, d, p;
	State(int ni, int nj, int nd, int np) {
		i = ni;
		j = nj;
		d = nd;
		p = np;
	}
	bool operator<(const State &other) const {
		return d > other.d;
	}
};

int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<int>> grid(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}
	vector<vector<vector<int>>> distance(3, vector<vector<int>>(r, vector<int>(c, 1e9)));
	priority_queue<State> pq;
	pq.push({State(0, 0, 0, 2)});
	distance[0][0][0] = distance[1][0][0] = distance[2][0][0] = 0;
	while (!pq.empty()) {
		State current = pq.top();
		pq.pop();
		if (current.d > distance[current.p][current.i][current.j]) {
			continue;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ni = current.i + di[dir];
			int nj = current.j + dj[dir];
			if (0 <= ni && ni < r && 0 <= nj && nj < c && current.d + grid[ni][nj] < distance[current.p][ni][nj]) {
				distance[current.p][ni][nj] = current.d + grid[ni][nj];
				pq.push(State(ni, nj, current.d + grid[ni][nj], current.p));
			}
		}
		if (current.p > 0) {
			for (int dir = 0; dir < 12; dir++) {
				int ni = current.i + dii[dir];
				int nj = current.j + djj[dir];
				if (0 <= ni && ni < r && 0 <= nj && nj < c && current.d < distance[current.p - 1][ni][nj]) {
					distance[current.p - 1][ni][nj] = current.d;
					pq.push(State(ni, nj, current.d, current.p - 1));
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", min(distance[0][i][j], min(distance[1][i][j], distance[2][i][j])));
		}
		printf("\n");
	}
}