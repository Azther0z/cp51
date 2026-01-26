// Buffet Line

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int start, int target, int k, vector<int>& food) {
	int l = start, r = food.size() - 1;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (food[mid] - food[start - 1] - (mid - start + 1)*k >= target ) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> food(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> food[i];
		food[i] += food[i - 1];
	}
	while (m--) {
		int start, target;
		cin >> start >> target;
		cout << binarySearch(start, target, k, food) << '\n';
	}
}