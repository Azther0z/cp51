// Maximum Contiguous Sum of Subsequence with Length Constraint
// Hard

#include <bits/stdc++.h>
using namespace std;

// Prefix sum variation of Kadane's algorithm
int main() {
	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0) {
			a[i] += a[i - 1];
		}
	}
	deque<int> dq;
	int result = a[0];
	dq.push_back(0);
	for (int i = 1; i < n; i++) {
		while (!dq.empty() && a[i] < a[dq.back()]) {
			dq.pop_back();
		}
		while (!dq.empty() && i - dq.front() >= w) {
			dq.pop_front();
		}
		result = max(result, a[i] - a[dq.front()]);
		dq.push_back(i);
	}
	cout << result;
}