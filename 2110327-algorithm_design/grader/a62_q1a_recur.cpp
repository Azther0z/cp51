// Recursive Matrix

#include <bits/stdc++.h>
using namespace std;

class Matrix {
	vector<vector<int>> matrix;
	int size;
  public:
	Matrix(int a, int b) {
		size = a;
		matrix.resize(1 << a, vector<int>(1 << a, 0));
		init(a, b, 0, 0);
	}
	void init(int a, int b, int row, int col) {
		if (a == 0) {
			matrix[row][col] = b;
			return;
		}
		init(a - 1, b, 2 * row, 2 * col);
		init(a - 1, b - 1, 2 * row, 2 * col + 1);
		init(a - 1, b + 1, 2 * row + 1, 2 * col);
		init(a - 1, b, 2 * row + 1, 2 * col + 1);
	}
	void print() {
		for (int i = 0; i < 1 << size; i++) {
			for (int j = 0; j < 1 << size; j++) {
				cout << matrix[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};

int main() {
	int a, b;
	cin >> a >> b;
	Matrix H(a, b);
	H.print();
}