// Hadamard
// Hard

#include <bits/stdc++.h>
using namespace std;

// H_n*(v_1,...,v_n) = {
// {H_n/2*(v_1,...,v_n/2)+H_n/2*(v_n/2+1,...,v_n)},
// {H_n/2*(v_1,...,v_n/2)-H_n/2*(v_n/2+1,...,v_n)}
// }
// R(l,r) = {
// {R(l,mid)+R(mid+1,r)},
// {R(l,mid)-R(mid+1,r)}
// }
vector<int> dnc(int l, int r, vector<int> &v) {
	if (l == r) {
		return {v[l]};
	}
	int mid = l + (r - l) / 2;
	vector<int> left = dnc(l, mid, v);
	vector<int> right = dnc(mid + 1, r, v);
	int size = r - l + 1;
	vector<int> result(size);
	for (int i = 0; i < size / 2; i++) {
		result[i] = left[i] + right[i];
	}
	for (int i = 0; i < size / 2; i++) {
		result[size / 2 + i] = left[i] - right[i];
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	vector<int> result = dnc(1, n, v);
	for (int r : result) {
		cout << r << ' ';
	}
}