// Check Mapping

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<bool> vec(n + 1, false);
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		if (y <= 0 || y > n || vec[y]) {
			cout << "NO";
			return 0;
		}
		vec[y] = true;
	}
	cout << "YES";
}