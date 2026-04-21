// Increasingly Consecutive

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
	int count = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			result += 1LL * count * count;
			count = 0;
		} else {
			count = max(count + 1, 2);
		}
	}
	result += 1LL * count * count;
	cout << result;
}