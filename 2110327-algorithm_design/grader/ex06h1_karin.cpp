// Karin Tower
// Hard, Trick

#include <bits/stdc++.h>
using namespace std;

int dFloor[] = {0, 0, 1, 1, 1};
int dRoom[] = { -1, 1, -1, 0, 1};

class DistanceMatrix {
 public:
	vector<vector<long long>> matrix;
	map<long long, DistanceMatrix> memo;
	DistanceMatrix() {}
	DistanceMatrix(vector<vector<long long>> adjm) {
		matrix = adjm;
	}
	DistanceMatrix matrixMatrixProduct(DistanceMatrix &other) {
		vector<vector<long long>> result(matrix.size(), vector<long long>(matrix.size(), 1e18));
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				for (int k = 0; k < matrix.size(); k++) {
					result[i][j] = min(result[i][j], matrix[i][k] + other.matrix[k][j]);
				}
			}
		}
		return DistanceMatrix(result);
	}
	DistanceMatrix matrixExponentiation(long long x) {
		if (x == 1) {
			return *this;
		}
		if (memo.find(x) != memo.end()) {
			return DistanceMatrix(memo[x]);
		}
		DistanceMatrix a = matrixExponentiation(x / 2);
		if (x & 1) {
			DistanceMatrix b = matrixExponentiation((x + 1) / 2);
			return memo[x] = a.matrixMatrixProduct(b);
		}
		return memo[x] = a.matrixMatrixProduct(a);
	}
	void display() {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				printf("%lld\t", (matrix[i][j] == 1e18 ? -1 : matrix[i][j]));
			}
			printf("\n");
		}
	}
};

int main() {
	int n, k, p;
	cin >> n >> k >> p;
	vector<vector<int>> cost(k, vector<int>(5));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> cost[i][j];
		}
	}
	vector<vector<long long>> horizontal(k, vector<long long>(k, 1e18));
	for (int room = 0; room < k; room++) {
		horizontal[room][room] = 0;
		for (int dir = 0; dir < 2; dir++) {
			int nRoom = (room + dRoom[dir] + k) % k;
			horizontal[room][nRoom] = cost[room][dir];
		}
	}
	for (int c = 0; c < k; c++) {
		for (int a = 0; a < k; a++) {
			for (int b = 0; b < k; b++) {
				horizontal[a][b] = min(horizontal[a][b], horizontal[a][c] + horizontal[c][b]);
			}
		}
	}
	DistanceMatrix hori(horizontal);
	vector<vector<long long>> vertical(k, vector<long long>(k, 1e18));
	for (int room = 0; room < k; room++) {
		for (int dir = 2; dir < 5; dir++) {
			int nRoom = (room + dRoom[dir] + k) % k;
			vertical[room][nRoom] = cost[room][dir];
		}
	}
	DistanceMatrix vert(vertical);
	DistanceMatrix base = hori.matrixMatrixProduct(vert);
	cout << base.matrixExponentiation(n - 1).matrixMatrixProduct(hori).matrix[0][p];
}