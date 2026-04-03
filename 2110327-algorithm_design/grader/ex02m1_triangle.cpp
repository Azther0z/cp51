// Number Triangle

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> triangle(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
		}
	}
	int result = 0;
	for (int j = 1; j <= n; j++) {
		result = max(result, triangle[n][j]);
	}
	cout << result;
}