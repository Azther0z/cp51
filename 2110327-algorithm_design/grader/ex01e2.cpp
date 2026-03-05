// Maximum Contiguous Sum

#include <bits/stdc++.h>
using namespace std;

// Direct Kadane's algorithm
// int main() {
// 	int n;
// 	cin >> n;
// 	vector<int> vec(n);
// 	for (int i = 0; i < n; i++) {
// 		cin >> vec[i];
// 	}
// 	long long result = vec[0];
// 	long long current = vec[0];
// 	for (int i = 1; i < n; i++) {
// 		current = max(1LL * vec[i], current + vec[i]);
// 		result = max(result, current);
// 	}
// 	cout << result;
// }

// Prefix sum variation of Kadane's algorithm
int main() {
	int n;
	cin >> n;
	vector<long long> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		if (i != 0) {
			vec[i] += vec[i - 1];
		}
	}
	long long result = vec[0];
	long long minPrefix = 0;
	for (int i = 1; i < n; i++) {
		result = max(result, vec[i] - minPrefix);
		minPrefix = min(minPrefix, vec[i]);
	}
	cout << result;
}