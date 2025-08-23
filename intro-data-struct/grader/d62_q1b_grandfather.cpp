// Grandfather

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	long long a, b;
	cin >> n >> m;
	map<long long, long long> mp;
	while (n--) {
		cin >> a >> b;
		mp[b] = a;
	}
	while (m--) {
		cin >> a >> b;
		if (mp[mp[a]] && mp[mp[a]] == mp[mp[b]] && a != b) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}