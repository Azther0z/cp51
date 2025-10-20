// Heap Before Node

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> vec;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		if (current == m) continue;
		vec.push_back(current);
		if (2 * current + 1 != m && 2 * current + 1 < n) {
			q.push(2 * current + 1);
		}
		if (2 * current + 2 != m && 2 * current + 2 < n) {
			q.push(2 * current + 2);
		}
	}
	cout << vec.size() << endl;
	sort(vec.begin(), vec.end());
	for (auto x : vec) {
		cout << x << ' ';
	}
}