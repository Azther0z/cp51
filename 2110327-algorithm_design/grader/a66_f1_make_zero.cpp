// Make Zero

#include <bits/stdc++.h>
using namespace std;

#define MOD 16777216

int main() {
	int x;
	cin >> x;
	priority_queue<pair<int, int>> pq;
	pq.push({0, x});
	while (!pq.empty()) {
		int current  = pq.top().second;
		int count = -pq.top().first;
		// cout << count << ' ' << current << endl;
		pq.pop();
		if (current == 0) {
			cout << count;
			return 0;
		}
		pq.push({ -(count + 1), (current + 1) % MOD});
		if (current % 2 == 0) {
			pq.push({ -(count + 1), (current * 2) % MOD});
		}
	}
}