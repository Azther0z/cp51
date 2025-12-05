// Histogram

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	map<string, int> mp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s]++;
	}
	for (auto x : mp) {
		if (x.second <= 1) {
			continue;
		}
		cout << x.first << ' ' << x.second << endl;
	}
}