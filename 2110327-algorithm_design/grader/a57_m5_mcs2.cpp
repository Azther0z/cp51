// Maximum Contiguous Sum of Circular Sequence
// Trick

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int minSum = arr[0];
	int result = 0;
	for (int i = 1; i < n; i++) {
		minSum = min(arr[i], minSum + arr[i]);
		result = max(result, sum - minSum);
	}
	if (result == 0) {
		result = -1e9;
		for (int i = 0; i < n; i++) {
			result = max(result, arr[i]);
		}
	}
	cout << result;
}