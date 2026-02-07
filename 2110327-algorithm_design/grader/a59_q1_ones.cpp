// Ones

#include <bits/stdc++.h>
using namespace std;

int recur(int n, int divider, int digitCount) {
	if (n == 0 || divider == 0) {
		return 0;
	}
	if (n == divider) {
		return digitCount;
	}
	int mult = n / divider;
	return min(recur(n - mult * divider, divider / 10, digitCount - 1) + digitCount * mult, recur((mult + 1) * divider - n, divider / 10, digitCount - 1) + digitCount * (mult + 1));
}

int main() {
	int n;
	cin >> n;
	cout << recur(n, 1111111111, 10);
}