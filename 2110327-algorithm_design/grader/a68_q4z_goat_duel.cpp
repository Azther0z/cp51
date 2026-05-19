// The Goat Duel

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long result = 0;
	for (int i = 0; i + 1 < n; i++) {
		result += a[i] * a[i + 1];
	}
	cout << result;
}