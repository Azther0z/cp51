// XOR Road

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> node(n);
	for (int i = 0; i < n; i++) {
		cin >> node[i];
	}
	set<int> connected;
	priority_queue<pair<int, int>> pq;
	pq.push({0, node[0]});
	long long result = 0;
	while (!pq.empty()) {
		long long weight = pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (connected.count(current)) {
			continue;
		}
		connected.insert(current);
		result += weight;
		for (int i = 0; i < n; i++) {
			if (!connected.count(node[i])) {
				pq.push({node[i]^current, node[i]});
			}
		}
	}
	cout << result;
}