// Self Describing Sequence
// Hard

#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	vector<long long> prefix({0, 1, 2, 2});
	long long sum = 0;
	for (int i = 3; sum < 2e9; i++) {
		for (int j = 0; j < prefix[i] && sum < 2e9; j++) {
			prefix.push_back(i);
			sum += i;
		}
	}
	for (int i = 1; i < prefix.size(); i++) {
		prefix[i] += prefix[i - 1];
	}
	while (q--) {
		int n;
		cin >> n;
		cout << lower_bound(prefix.begin(), prefix.end(), n) - prefix.begin() << endl;
	}
}