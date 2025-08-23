// Time After

#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, m, x;
	cin >> h >> m >> x;
	m = m + x;
	h = (h + m / 60) % 24;
	m = m % 60;
	if (h < 10) {
		cout << 0;
	}
	cout << h << ' ';
	if (m < 10) {
		cout << 0;
	}
	cout << m;
}