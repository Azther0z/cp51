// Matrix Modulo

#include <bits/stdc++.h>
using namespace std;

vector<int> matrixMultiply(vector<int>& a, vector<int>& b, int k) {
	vector<int> tmp(4);
	tmp[0] = (a[0] * b[0] + a[1] * b[2]) % k;
	tmp[1] = (a[0] * b[1] + a[1] * b[3]) % k;
	tmp[2] = (a[2] * b[0] + a[3] * b[2]) % k;
	tmp[3] = (a[2] * b[1] + a[3] * b[3]) % k;
	return tmp;
}

// dnc(n) = (dnc(n/2)*dnc((n+1)/2))%k
map<int, vector<int>> memo;
vector<int> dnc(int n, int k, vector<int>& matrix) {
	// cout << n << endl;
	if (memo.count(n)) {
		return memo[n];
	}
	if (n == 1) {
		return memo[n] = matrix;
	}
	vector<int> a = dnc(n / 2, k, matrix);
	if (n & 1 == 0) {
		return memo[n] = matrixMultiply(a, a, k);
	}
	vector<int> b = dnc((n + 1) / 2, k, matrix);
	return memo[n] = matrixMultiply(a, b, k);
}

int main() {
	int n, k;
	vector<int> matrix(4);
	cin >> n >> k;
	for (int i = 0; i < 4; i++) {
		cin >> matrix[i];
	}
	matrix = dnc(n, k, matrix);
	for (int i = 0; i < 4; i++) {
		cout << matrix[i] << ' ';
	}
}