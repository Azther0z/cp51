// Buffet Line

#include <bits/stdc++.h>
using namespace std;

int main() {
	int f, w, n;
	cin >> f >> w >> n;
	vector<int> pos(f);
	for (int i = 0; i < f; i++) {
		cin >> pos[i];
	}
	sort(pos.begin(), pos.end());
	vector<int> result;
	for (int i = 0; i < f; i++) {
		if (result.empty()) {
			result.push_back(pos[i]);
		} else if (pos[i] > result.back() + w + w) {
			result.push_back(pos[i]);
		}
	}
	cout << result.size();
}