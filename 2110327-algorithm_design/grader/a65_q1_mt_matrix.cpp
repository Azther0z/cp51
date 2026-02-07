// MT Matrix
// Hard

#include <bits/stdc++.h>
using namespace std;

class Matrix {
	vector<vector<int>> matrix;
  public:
	Matrix(vector<vector<int>> vec) {
		matrix = vec;
	}
	int getValue(int n, long long r, long long c, int neg) {
		// cout << r << ' ' << c << endl;
		if (n == 1) {
			return matrix[r][c] * neg;
		}
		long long half = 1LL << (n - 1);
		if (r < half && c < half) {
			return getValue(n - 1, r, c, neg);
		}
		if (r < half && c >= half) {
			return getValue(n - 1, c - half, r, neg);
		}
		if (r >= half && c < half) {
			return getValue(n - 1,  r - half, c, -neg);
		}
		return getValue(n - 1, c - half, r - half, -neg);
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(2, vector<int>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> vec[i][j];
		}
	}
	// for (int i = 0; i < 8; i++) {
	// 	for (int j = 0; j < 8; j++) {
	// 		Matrix matrix(vec);
	// 		cout << matrix.getValue(3, i, j) << '\t';
	// 	}
	// 	cout << endl;
	// }
	while (m--) {
		long long r, c;
		cin >> r >> c;
		r--, c--;
		Matrix matrix(vec);
		cout << matrix.getValue(n, r, c, 1) << endl;
	}
}