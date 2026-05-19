// Guitar's Array 3
// Hard

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> source;

class Heuristic {
  public:
	int i, j, size;
	vector<vector<int>> covered;
	Heuristic(vector<vector<int>> c, int ni, int nj) {
		i = ni;
		j = nj;
		covered = c;
		size = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (covered[i][j]) {
					size++;
				}
			}
		}
	}
	bool operator<(const Heuristic other) const {
		return size > other.size;
	}
};

Heuristic place(int ci, int cj, vector<string> &source, int n, int m) {
	vector<vector<int>> covered(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		if (source[i][cj] == '.') {
			covered[i][cj] = 1;
		}
	}
	for (int j = 0; j < m; j++) {
		if (source[ci][j] == '.') {
			covered[ci][j] = 1;
		}
	}
	for (int i = ci, j = cj; i < n && j < m; i++, j++) {
		if (source[i][j] == '.') {
			covered[i][j] = 1;
		}
	}
	for (int i = ci, j = cj; i >= 0 && j < m; i--, j++) {
		if (source[i][j] == '.') {
			covered[i][j] = 1;
		}
	}
	for (int i = ci, j = cj; i < n && j >= 0; i++, j--) {
		if (source[i][j] == '.') {
			covered[i][j] = 1;
		}
	}
	for (int i = ci, j = cj; i >= 0 && j >= 0; i--, j--) {
		if (source[i][j] == '.') {
			covered[i][j] = 1;
		}
	}
	int di[] = { -2, -2, -1, -1, 1, 1, 2, 2};
	int dj[] = { -1, 1, -2, 2, 2, -2, 1, -1};
	for (int dir = 0; dir < 8; dir++) {
		int ni = ci + di[dir];
		int nj = cj + dj[dir];
		if (0 <= ni && ni < n && 0 <= nj && nj < m && source[ni][nj] == '.') {
			covered[ni][nj] = 1;
		}
	}
	return Heuristic(covered, ci, cj);
}

bool complete(vector<vector<int>> &covered) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (source[i][j] == '.' && !covered[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int resultCount = 1e9;
vector<string> resultBoard;
void dfs(int current, int placeCount, vector<vector<int>> &covered, vector<string> &board, vector<Heuristic> &heu) {
	if (complete(covered)) {
		if (placeCount < resultCount) {
			resultCount = placeCount;
			resultBoard = board;
		}
		return;
	}
	if (current == heu.size()) {
		return;
	}
	if (placeCount >= resultCount) {
		return;
	}
	int bestImprovement = 0;
	int next = -1;
	for (int i = current; i < heu.size(); i++) {
		int improvement = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (source[i][j] == '.' && !covered[i][j] && heu[current].covered[i][j]) {
					improvement++;
				}
			}
		}
		if (improvement > bestImprovement) {
			bestImprovement = improvement;
			next = i;
		}
	}
	if (next != -1) {
		board[heu[next].i][heu[next].j] = 'X';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (source[i][j] == '.' && heu[next].covered[i][j]) {
					covered[i][j]++;
				}
			}
		}
		dfs(next + 1, placeCount + 1, covered, board, heu);
		board[heu[next].i][heu[next].j] = '.';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (source[i][j] == '.' && heu[next].covered[i][j]) {
					covered[i][j]--;
				}
			}
		}
	}
	dfs(current + 1, placeCount, covered, board, heu);
}

int main() {
	cin >> n >> m;
	source.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> source[i];
	}
	vector<Heuristic> heu;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (source[i][j] == '.') {
				heu.push_back(place(i, j, source, n, m));
			}
		}
	}
	sort(heu.begin(), heu.end());
	vector<vector<int>> covered(n, vector<int>(m, 0));
	vector<string> board(source);
	dfs(0, 0, covered, board, heu);
	for (string r : resultBoard) {
		cout << r << endl;
	}
}