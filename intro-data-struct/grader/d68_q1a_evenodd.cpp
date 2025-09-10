// Even Odd

#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	int e = 0;
	int o = 0;
	map<int, int> count;
	while (q--) {
		int x;
		cin >> x;
		if (count.find(x) == count.end()) {
			o++;
			count[x]++;
		} else if (count[x] % 2 == 0) {
			e--;
			o++;
			count[x]++;
		} else {
			e++;
			o--;
			count[x]++;
		}
		cout << e << ' ' << o << endl;
	}
}