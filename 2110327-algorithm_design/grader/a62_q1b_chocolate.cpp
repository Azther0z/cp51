// Chocolate

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	// count[i] represents number of way to eat chocolate at size i
	vector<int> count(n + 1, 0);
	count[0] = 1;
	vector<int> possible(k);
	for (int j = 0; j < k; j++) {
		cin >> possible[j];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			if (i - possible[j] < 0) {
				continue;
			}
			count[i] += count[i - possible[j]];
			count[i] %= 1000003;
		}
	}
	cout << count[n];
}