// Pair Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> count(2000001, 0);
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		count[arr[i]]++;
	}
	while (m--) {
		int target;
		cin >> target;
		bool check = false;
		for (int i = 0; i < n; i++) {
			if (arr[i] + arr[i] == target && count[arr[i]] < 2) {
				continue;
			}
			if (target > arr[i] && count[target - arr[i]]) {
				check = true;
				break;
			}
		}
		cout << (check ? "YES\n" : "NO\n");
	}
}