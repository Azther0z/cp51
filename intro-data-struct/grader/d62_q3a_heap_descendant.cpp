// Heap Descendant

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a;
	cin >> n >> a;
	queue<int> q;
	q.push(a);
	vector<int> vec;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		vec.push_back(current);
		if (2 * current + 1 < n) {
			q.push(2 * current + 1);
		}
		if (2 * current + 2 < n) {
			q.push(2 * current + 2);
		}
	}
	cout << vec.size() << endl;
	for (auto x : vec) {
		cout << x << ' ';
	}
}