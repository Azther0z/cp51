// K-ary Heap Height

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << n - 1;
		return 0;
	}
	int height = 0;
	n--;
	while (n > 0) {
		n = (n - 1) / k;
		height++;
	}
	cout << height;
}