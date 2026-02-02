// Lawn Mowing

#include <bits/stdc++.h>
using namespace std;

long long binarySearch(int a, long long b, int k, vector<long long>& price) {
	int l = a, r = price.size();
	long long result = 0;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (price[mid] - price[a - 1] + (mid - a + 1)*k <= b) {
			result = max(result, price[mid] - price[a - 1]);
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return result;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> price(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> price[i];
		price[i] += price[i - 1];
	}
	while (m--) {
		int a;
		long long b;
		cin >> a >> b;
		a++;
		cout << binarySearch(a, b, k, price) << endl;
	}
}