// Insertion Sort Count
// Trick

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	vector<int> mp(2e5 + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		mp[vec[i]] = i;
	}
	while (m--) {
		int x;
		cin >> x;
		int count = 0;
		for (int i = mp[x] - 1; i >= 0; i--) {
			count += (vec[i] > x);
		}
		cout << count << endl;
	}
}