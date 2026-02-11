// Inversion

#include <bits/stdc++.h>
using namespace std;

int dnc(int l, int r, vector<int>& vec) {
	if (r - l == 1) {
		return 0;
	}
	int mid = l + (r - l) / 2;
	int count = dnc(l, mid, vec) + dnc(mid, r, vec);
	vector<int> tmp(vec);
	int lPointer = l;
	int rPointer = mid;
	int index = l;
	while (lPointer < mid && rPointer < r) {
		if (vec[lPointer] > vec[rPointer]) {
			count += mid - lPointer;
			tmp[index] = vec[rPointer];
			index++;
			rPointer++;
		} else {
			tmp[index] = vec[lPointer];
			index++;
			lPointer++;
		}
	}
	while (lPointer < mid) {
		tmp[index] = vec[lPointer];
		lPointer++;
		index++;
	}
	while (rPointer < r) {
		tmp[index] = vec[rPointer];
		rPointer++;
		index++;
	}
	vec = tmp;
	return count;
}

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	cout << dnc(0, n, vec);
}