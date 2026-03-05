// Goat
// Hard

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// R(n,1) = R(n-1,1)+R(n-1,2)
// R(n,2) = R(n-2,1)+R(n-2,4)
// R(n,4) = R(n-4,4)+R(n-4,2)
// [transition matrix]*[state vector] = [next state vector]
// [state vector] = [R(n-1,1),R(n-1,2),R(n-1,4),R(n-2,1),R(n-2,2),R(n-2,4),R(n-3,1),R(n-3,2),R(n-3,4),R(n-4,1),R(n-4,2),R(n-4,4)]
// [next state vector] = [R(n,1),R(n,2),R(n,4),R(n-1,1),R(n-1,2),R(n-1,4),R(n-2,1),R(n-2,2),R(n-2,4),R(n-3,1),R(n-3,2),R(n-3,4)]
// When we met checkpoint A, set R(A-1/A-2/A-3,X) of [next state vector] to zero, so next transition will only consider path that perfectly ended at R(A,X)

class Matrix {
  public:
	vector<vector<long long>> matrix;
	map<long long, Matrix> memo;

	Matrix() {}

	Matrix(vector<vector<long long>> vec) {
		matrix = vec;
	}

	Matrix matrixMatrixProduct(Matrix &other) {
		vector<vector<long long>> result(matrix.size(), vector<long long>(matrix.size(), 0));
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				for (int k = 0; k < matrix.size(); k++) {
					result[i][j] += matrix[i][k] * other.matrix[k][j];
					result[i][j] %= MOD;
				}
			}
		}
		return Matrix(result);
	}

	Matrix exponentiation(long long n) {
		if (memo.find(n) != memo.end()) {
			return memo[n];
		}
		if (n == 1) {
			return memo[n] = Matrix(matrix);
		}
		Matrix a = exponentiation(n / 2);
		if (n & 1) {
			Matrix b = exponentiation((n + 1) / 2);
			return memo[n] = a.matrixMatrixProduct(b);
		}
		return memo[n] = a.matrixMatrixProduct(a);
	}

	vector<long long> matrixVectorProduct(vector<long long> &vec) {
		vector<long long> result(vec.size(), 0);
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec.size(); j++) {
				result[i] += matrix[i][j] * vec[j];
				result[i] %= MOD;
			}
		}
		return result;
	}
};

vector<long long> getBaseCase(vector<bool> check) {
	vector<long long> one(5, 0), two(5, 0), four(5, 0);
	// Hand written recurrence relation on basecase
	one[1] = 1;
	two[1] = 0;
	four[1] = 0;
	one[2] = 1;
	two[2] = (check[1] ? 0 : 1);
	four[2] = 0;
	one[3] = one[2] + two[2];
	two[3] = (check[2] ? 0 : 1);
	four[3] = 0;
	one[4] = one[3] + two[3];
	two[4] = (check[3] ? 0 : one[2] + four[2]);
	four[4] = (check[1] || check[2] || check[3] ? 0 : 1);
	if (check[4]) {
		return {one[4], two[4], four[4], 0, 0, 0, 0, 0, 0, 0, 0, 0};
	}
	return {one[4], two[4], four[4], one[3], two[3], four[3], one[2], two[2], four[2], one[1], two[1], four[1]};
}

int main() {
	long long n, k;
	cin >> n >> k;
	vector<long long> stop(k + 1, 0);
	vector<bool> check(5, false);
	for (int i = 1; i <= k; i++) {
		cin >> stop[i];
		if (stop[i] <= 4) {
			check[stop[i]] = true;
		}
	}
	stop[0] = 4;
	if (stop.back() != n) {
		stop.push_back(n);
	}
	vector<vector<long long>> tmp({
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	});
	Matrix mat(tmp);
	vector<long long> vec = getBaseCase(check);
	for (int i = 1; i < stop.size(); i++) {
		if (stop[i] <= 4) {
			stop[i] = 4;
			continue;
		}
		Matrix forward = mat.exponentiation(stop[i] - stop[i - 1]);
		vec = forward.matrixVectorProduct(vec);
		for (int j = 3; j < 12; j++) {
			vec[j] = 0;
		}
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (n == 2) {
		cout << (vec[6] + vec[7] + vec[8]) % MOD;
		return 0;
	}
	if (n == 3) {
		cout << (vec[3] + vec[4] + vec[5]) % MOD;
		return 0;
	}
	cout << (vec[0] + vec[1] + vec[2]) % MOD;
}