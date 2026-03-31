// Columbia

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
	bool operator<(const State other)const {
		return d > other.d;
	}
};

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<int>> grid(r, vector<int>(c)), distance(r, vector<int>(c, 1e9));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}
	distance[0][0] = 0;
	priority_queue<State> pq;
	pq.push(State(0, 0, 0));
	while (!pq.empty()) {
		State current = pq.top();
		pq.pop();
		if (current.d > distance[current.i][current.j]) {
			continue;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ni = current.i + di[dir];
			int nj = current.j + dj[dir];
			if (0 <= ni && ni < r && 0 <= nj && nj < c && current.d + grid[ni][nj] < distance[ni][nj]) {
				distance[ni][nj] = current.d + grid[ni][nj];
				pq.push(State(ni, nj, current.d + grid[ni][nj]));
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", distance[i][j]);
		}
		printf("\n");
	}
}