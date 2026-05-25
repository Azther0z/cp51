// Guitar's Array 3
// Hard
<<<<<<< HEAD
=======
// pi:openai-codex/gpt-5.5
>>>>>>> c64e012 (algorithm_design: Quiz 4)

#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
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
=======
// Model the problem as minimum set cover.
// Number every usable cell '.' from 0..k-1. Placing X on a cell is one possible
// set, and that set contains every cell reached by row, column, diagonal, or
// knight-move signal. coverMask[p] stores this set as a bitset.
//
// Also keep the reverse relation senders[c]: all placements p that can cover c.
// During DFS, choose an uncovered cell c that currently has the fewest useful
// senders. This is the hardest cell to cover, so branching on it first usually
// keeps the search small. For that cell, try placements that cover more new cells
// before weaker placements. bestCount is the current upper bound for pruning.

const int MAXC = 144; // 12 * 12 maximum usable cells

int n, m, k;
vector<string> source;
vector<pair<int, int>> cells;
int id[12][12];

vector<bitset<MAXC>> coverMask; // coverMask[p] = cells covered by placing at p
vector<vector<int>> senders;     // senders[c] = placements that can cover c
vector<int> coverSize;
vector<int> answer, currentChosen;
int bestCount;
bitset<MAXC> fullMask;           // all usable cells are covered

bool inBound(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void addCoveredCell(int p, int ci, int cj, vector<int> &seen) {
	// Add cell (ci, cj) into placement p's coverage, ignoring duplicates.
	// Duplicates happen because the placed cell is reached by many directions.
	if (!inBound(ci, cj) || source[ci][cj] != '.') return;
	int c = id[ci][cj];
	if (seen[c]) return;
	seen[c] = 1;
	coverMask[p].set(c);
	senders[c].push_back(p);
}

void buildCoverage(int p) {
	// Precompute every usable cell covered if X is placed at cells[p].
	// Signals pass through '#', so only board bounds stop each line.
	int pi = cells[p].first;
	int pj = cells[p].second;
	vector<int> seen(k, 0);

	// Same column and same row.
	for (int i = 0; i < n; i++) addCoveredCell(p, i, pj, seen);
	for (int j = 0; j < m; j++) addCoveredCell(p, pi, j, seen);

	// Four diagonals.
	for (int i = pi, j = pj; i < n && j < m; i++, j++) addCoveredCell(p, i, j, seen);
	for (int i = pi, j = pj; i >= 0 && j < m; i--, j++) addCoveredCell(p, i, j, seen);
	for (int i = pi, j = pj; i < n && j >= 0; i++, j--) addCoveredCell(p, i, j, seen);
	for (int i = pi, j = pj; i >= 0 && j >= 0; i--, j--) addCoveredCell(p, i, j, seen);

	// Knight moves.
	int di[] = { -2, -2, -1, -1, 1, 1, 2, 2};
	int dj[] = { -1, 1, -2, 2, 2, -2, 1, -1};
	for (int d = 0; d < 8; d++) addCoveredCell(p, pi + di[d], pj + dj[d], seen);
}

int chooseHardestUncovered(const bitset<MAXC> &covered) {
	// Pick an uncovered cell with the fewest placements that add new coverage.
	// Tie-break by smaller best possible gain, because it is more constrained.
	int target = -1;
	int bestChoices = INT_MAX;
	int bestMaxGain = INT_MAX;

	for (int c = 0; c < k; c++) {
		if (covered[c]) continue;

		int choices = 0, maxGain = 0;
		for (int p : senders[c]) {
			int gain = (int)((coverMask[p] & ~covered).count());
			if (gain > 0) {
				choices++;
				maxGain = max(maxGain, gain);
			}
		}

		if (choices < bestChoices || (choices == bestChoices && maxGain < bestMaxGain)) {
			bestChoices = choices;
			bestMaxGain = maxGain;
			target = c;
		}
	}
	return target;
}

void dfs(bitset<MAXC> covered) {
	// currentChosen is the list of placements already used.
	// covered is passed by value because bitset is small and this makes undo free.
	int used = (int)currentChosen.size();
	if (used >= bestCount) return;
	if (covered == fullMask) {
		bestCount = used;
		answer = currentChosen;
		return;
	}

	int uncovered = k - (int)covered.count();
	int maxGain = 0;
	for (int p = 0; p < k; p++) {
		maxGain = max(maxGain, (int)((coverMask[p] & ~covered).count()));
	}
	if (maxGain == 0) return;
	if (used + (uncovered + maxGain - 1) / maxGain >= bestCount) return;

	int target = chooseHardestUncovered(covered);
	if (target == -1) return;

	// Branch only on placements that can cover the selected target cell.
	// Store {-gain, p} so normal ascending sort tries larger gain first.
	vector<pair<int, int>> choices;
	for (int p : senders[target]) {
		int gain = (int)((coverMask[p] & ~covered).count());
		if (gain > 0) choices.push_back({ -gain, p});
	}
	sort(choices.begin(), choices.end());

	for (int i = 0; i < (int)choices.size(); i++) {
		int p = choices[i].second;
		currentChosen.push_back(p);
		dfs(covered | coverMask[p]);
		currentChosen.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	source.resize(n);
	for (int i = 0; i < n; i++) cin >> source[i];

	// Compress only usable cells into ids. '#' cells never need to be covered.
	memset(id, -1, sizeof(id));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (source[i][j] == '.') {
				id[i][j] = (int)cells.size();
				cells.push_back({i, j});
			}
		}
	}

	k = (int)cells.size();
	coverMask.assign(k, bitset<MAXC>());
	senders.assign(k, vector<int>());
	for (int c = 0; c < k; c++) fullMask.set(c);

	// Build both coverMask[p] and reverse senders[c].
	for (int p = 0; p < k; p++) buildCoverage(p);

	coverSize.resize(k);
	for (int p = 0; p < k; p++) coverSize[p] = (int)coverMask[p].count();
	// Static ordering for a good default; DFS also re-sorts by current new gain.
	for (int c = 0; c < k; c++) {
		sort(senders[c].begin(), senders[c].end(), [&](int a, int b) {
			return coverSize[a] > coverSize[b];
		});
	}

	if (k == 0) {
		for (string row : source) cout << row << '\n';
		return 0;
	}

	bestCount = k + 1;
	bitset<MAXC> empty;
	dfs(empty);

	// Reconstruct one optimal board from the chosen placement ids.
	vector<string> board = source;
	for (int p : answer) {
		int i = cells[p].first;
		int j = cells[p].second;
		board[i][j] = 'X';
	}
	for (string row : board) cout << row << '\n';
}
>>>>>>> c64e012 (algorithm_design: Quiz 4)
