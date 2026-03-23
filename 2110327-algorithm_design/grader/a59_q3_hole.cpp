// Hole

#include <bits/stdc++.h>
using namespace std;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

class State {
  public:
	int d, i, j;
	State() {}
	State(int nd, int ni, int nj) {
		d = nd;
		i = ni;
		j = nj;
	}
	bool operator<(const State &other) const {
		return d > other.d;
	}
};

int main() {
	int n, si, sj;
	cin >> n >> si >> sj;
	vector<vector<bool>> grid(1001, vector<bool>(1001, false));
	while (n--) {
		int i, j;
		cin >> i >> j;
		grid[i][j] = true;
	}
	priority_queue<State> pq;
	vector<vector<int>> distance(1001, vector<int>(1001, 1e9));
	pq.push(State(0, si, sj));
	distance[si][sj] = 0;
	int result = 1e9;
	while (!pq.empty()) {
		int cd = pq.top().d;
		int ci = pq.top().i;
		int cj = pq.top().j;
		pq.pop();
		if (cd > distance[ci][cj]) {
			continue;
		}
		if (ci == 1 || ci == 1000 || cj == 1 || cj == 1000) {
			result = min(result, cd);
			continue;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ni = ci + di[dir];
			int nj = cj + dj[dir];
			if (1 <= ni && ni <= 1000 && 1 <= nj && nj <= 1000 && cd + grid[ni][nj] < distance[ni][nj]) {
				pq.push(State(cd + grid[ni][nj], ni, nj));
				distance[ni][nj] = cd + grid[ni][nj];
			}
		}
	}
	cout << result;
}