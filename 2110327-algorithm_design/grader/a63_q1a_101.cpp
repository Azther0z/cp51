// Bit String without 101
// Hard

#include <bits/stdc++.h>
using namespace std;

#define MOD 100000007

// Transform problem to graph by Finite State Machine
// We can get distinct path of length n by calculate A^n when A is Adjacency Matrix
// --|00|01|10|11
// 00| 1| 1| 0| 0
// 01| 0| 0| 1| 1
// 10| 1| 0| 0| 0
// 11| 0| 0| 1| 1

class Matrix {
  public:
	vector<vector<long long>> matrix;
	map<long long, Matrix> memo;
	int size;
	Matrix() {
		size = 0;
	}
	Matrix(vector<vector<long long>> vec) {
		matrix = vec;
		size = vec.size();
	}
	Matrix multiply(Matrix& other) {
		vector<vector<long long>> result(size, vector<long long>(size, 0));
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					result[i][j] += matrix[k][j] * other.matrix[i][k];
					result[i][j] %= MOD;
				}
			}
		}
		Matrix tmp(result);
		return tmp;
	}
	Matrix exponentiation(long long k) {
		if (memo.count(k)) {
			return memo[k];
		}
		if (k == 1) {
			return memo[k] = matrix;
		}
		Matrix a = exponentiation(k / 2);
		if (k & 1) {
			Matrix b = exponentiation((k + 1) / 2);
			return memo[k] = a.multiply(b);
		}
		return memo[k] = a.multiply(a);
	}
	long long getSum() {
		long long result = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				result += matrix[i][j];
				result %= MOD;
			}
		}
		return result;
	}
};

int main() {
	long long n;
	cin >> n;
	Matrix matrix({
		{1, 1, 0, 0},
		{0, 0, 1, 1},
		{1, 0, 0, 0},
		{0, 0, 1, 1}
	});
	matrix = matrix.exponentiation(n - 2);
	cout << matrix.getSum();
}