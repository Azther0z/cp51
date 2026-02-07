// Number One

#include <bits/stdc++.h>
using namespace std;

long long getSize(int n, map<int, long long>& sizeMap) {
	if (n == 1) {
		return 1;
	}
	if (sizeMap.count(n)) {
		return sizeMap[n];
	}
	return sizeMap[n] = 2 * getSize(n / 2, sizeMap) + 1;
}

bool isOne(int n, long long index, long long left, map<int, long long>& sizeMap) {
	// cout << index << ' ' << n << ' ' << left << endl;
	if (n == 1) {
		return 1;
	}
	long long size = getSize(n / 2, sizeMap);
	if (index < left + size) {
		return isOne(n / 2, index, left, sizeMap);
	} else if (index > left + size) {
		return isOne(n / 2, index, left + size + 1, sizeMap);
	}
	return n % 2;
}

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	map<int, long long> sizeMap;
	int sum = 0;
	for (int i = l; i <= r; i++) {
		sum += isOne(n, i, 1, sizeMap);
	}
	cout << sum;
}