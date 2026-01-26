// Triple Sum
// Trick

#include <bits/stdc++.h>
using namespace std;

bool twoPointer(vector<int>& arr, int target, int n) {
	for (int a = 0; a < n; a++) {
		int l = a + 1, r = n - 1;
		while (l < r) {
			if (arr[a] + arr[l] + arr[r] == target) {
				return true;
			} else if (arr[a] + arr[l] + arr[r] < target) {
				l++;
			} else if (arr[a] + arr[l] + arr[r] > target) {
				r--;
			}
		}
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	while (m--) {
		int target;
		cin >> target;
		cout << (twoPointer(arr, target, n) ? "YES\n" : "NO\n");
	}
}