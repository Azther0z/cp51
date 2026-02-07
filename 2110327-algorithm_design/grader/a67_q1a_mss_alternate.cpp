// Maximum Subarray Alternating Sum

#include <bits/stdc++.h>
using namespace std;


// dp[i][j] is maximum subarray sum ended at index i using j*vec[i]
// dp[i][1] = max(dp[i-1][-1]+vec[i],vec[i])
// dp[i][-1] = dp[i-1][1]-vec[i]

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	long long result = -1e18;
	long long positive = -1e18;
	long long negative = -1e18;
	for (int i = 0; i < n; i++) {
		long long newPositive = max(negative + vec[i], (long long)vec[i]);
		long long newNegative = positive - vec[i];
		positive = newPositive;
		negative = newNegative;
		result = max(result, positive);
		result = max(result, negative);
	}
	cout << result;
}