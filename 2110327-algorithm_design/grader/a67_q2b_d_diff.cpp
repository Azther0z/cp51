// Difference Less Than

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long result = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		result += 1LL * (upper_bound(a.begin(), a.end(), a[i] + d) - (a.begin() + i + 1));
	}
	cout << result;
}