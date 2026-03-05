// Similar String

#include <bits/stdc++.h>
using namespace std;

bool same(int al, int bl, int len, string& a, string& b) {
	for (int i = 0; i < len; i++) {
		if (a[al + i] != b[bl + i]) {
			return false;
		}
	}
	return true;
}

bool dnc(int al, int bl, int len, string& a, string& b) {
	if (len == 0) {
		return false;
	}
	if (same(al, bl, len, a, b)) {
		return true;
	}
	int half = len / 2;
	if (dnc(al, bl, half, a, b) && dnc(al + half, bl + half, half, a, b)) {
		return true;
	}
	if (dnc(al, bl + half, half, a, b) && dnc(al + half, bl, half, a, b)) {
		return true;
	}
	return false;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << (dnc(0, 0, a.size(), a, b) ? "YES\n" : "NO\n");
}