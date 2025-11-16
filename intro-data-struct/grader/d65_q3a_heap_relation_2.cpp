// Heap Node Relation 2 (K-ary heap)

#include <bits/stdc++.h>
using namespace std;

bool checkAncestor(long long s, long long a, long long b) {
	while (a > 0) {
		a = (a - 1) / s;
		if (a == b) {
			return true;
		}
	}
	return false;
}

int height(long long s, long long x) {
	int h = 0;
	while (x > 0) {
		x = (x - 1) / s;
		h++;
	}
	return h;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		long long s, a, b;
		cin >> s >> a >> b;
		if ((a - 1) / s == b || (b - 1) / s == a) {
			cout << "1 ";
			continue;
		}
		if (checkAncestor(s, a, b) || checkAncestor(s, b, a)) {
			cout << "2 ";
			continue;
		}
		if (height(s, a) != height(s, b)) {
			cout << "3 ";
			continue;
		}
		cout << "4 ";
	}
}