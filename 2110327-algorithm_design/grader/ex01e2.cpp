// Maximum Contiguous Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	long long result = vec[0];
	long long current = vec[0];
	for (int i = 1; i < n; i++) {
		current = max(1LL * vec[i], current + vec[i]);
		result = max(result, current);
	}
	cout << result;
}