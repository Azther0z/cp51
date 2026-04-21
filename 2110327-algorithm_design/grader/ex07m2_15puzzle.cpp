// 15 Puzzle

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> target({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}});
class State {
  public:
	int i, j, cost, heu;
	vector<vector<int>> board;
	State(int ci, int cj, int c, vector<vector<int>> b) {
		i = ci;
		j = cj;
		board = b;
		cost = c;
		heu = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				heu += getManhattanCost(i, j, b[i][j]);
			}
		}
	}
	int getManhattanCost(int ti, int tj, int t) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (target[i][j] == t) {
					return abs(ti - i) + abs(tj - j);
				}
			}
		}
		return 0;
	}
	bool operator<(const State &other) const {
		return cost + heu > other.cost + other.heu;
	}
	bool completed() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[i][j] != target[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
};

int main() {
	vector<vector<int>> source(4, vector<int>(4));
	int si, sj;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> source[i][j];
			if (source[i][j] == 0) {
				si = i;
				sj = j;
			}
		}
	}
	priority_queue<State> pq;
	map<vector<vector<int>>, int> distance;
	int di[] = {0, 0, 1, -1};
	int dj[] = {1, -1, 0, 0};
	pq.push(State(si, sj, 0, source));
	while (!pq.empty()) {
		State current = pq.top();
		pq.pop();
		if (current.completed()) {
			cout << current.cost;
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ni = current.i + di[dir];
			int nj = current.j + dj[dir];
			if (0 <= ni && ni < 4 && 0 <= nj && nj < 4) {
				swap(current.board[current.i][current.j], current.board[ni][nj]);
				if (distance[current.board] == 0 || current.cost + 1 < distance[current.board]) {
					distance[current.board] = current.cost + 1;
					pq.push(State(ni, nj, current.cost + 1, current.board));
				}
				swap(current.board[current.i][current.j], current.board[ni][nj]);
			}
		}
	}
}