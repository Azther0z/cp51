// Shoot Em Up

#include <bits/stdc++.h>
using namespace std;

void recur(int current, int n, int w, string s, vector<string>& result) {
	if (s.length() == n) {
		result.push_back(s);
		return;
	}
	if (current - 1 >= 1) {
		recur(current - 1, n, w, s + 'D', result);
	}
	recur(current, n, w, s + 'S', result);
	if (current + 1 <= w) {
		recur(current + 1, n, w, s + 'U', result);
	}
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0);
	int n, w, b;
	cin >> n >> w >> b;
	vector<string> result;
	recur(b, n, w, "", result);
	for (auto x : result) {
		cout << x << '\n';
	}
}