// Two Maximum Contiguous Sum of Subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), prefix(n, -1e9), suffix(n, -1e9);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int current = a[0];
	prefix[0] = current;
	for (int i = 1; i < n; i++) {
		current = max(a[i], current + a[i]);
		prefix[i] = max(current, prefix[i - 1]);
	}
	current = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		current = max(a[i], current + a[i]);
		suffix[i] = max(current, suffix[i - 1]);
	}
	int result = -1e9;
	for (int i = 0; i + 1 < n; i++) {
		result = max(result, prefix[i] + suffix[i + 1]);
		result = max(result, prefix[i]);
		result = max(result, suffix[i]);
	}
	cout << result;
}