// Consecutive Ones

#include <bits/stdc++.h>
using namespace std;

void recur(string current, int consecutive, bool valid, int n, int k) {
	if (consecutive >= k) {
		valid = true;
	}
	if (current.size() == n) {
		if (valid) {
			cout << current << endl;
		}
		return;
	}
	if (n - current.size() < k - consecutive && !valid) {
		return;
	}
	recur(current + '0', 0, valid, n, k);
	recur(current + '1', consecutive + 1, valid, n, k);
}

int main() {
	int n, k;
	cin >> n >> k;
	string ones;
	for (int i = 0; i < k; i++) {
		ones += '1';
	}
	recur("", 0, false, n, k);
}