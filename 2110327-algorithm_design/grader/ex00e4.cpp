// Gen Barcode

#include <bits/stdc++.h>
using namespace std;

void recur(int oneLeft, int zeroLeft, string current) {
	if (!oneLeft && !zeroLeft) {
		cout << current << endl;
		return;
	}
	if (oneLeft) {
		recur(oneLeft - 1, zeroLeft, current + '1');
	}
	if (zeroLeft) {
		recur(oneLeft, zeroLeft - 1, current + '0');
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	recur(a, b - a, "");
}