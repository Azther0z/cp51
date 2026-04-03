// Task Planning

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> adjl(n);
	vector<int> inDeg(n, 0), result;
	for (int i = 0; i < n; i++) {
		int m, prev;
		cin >> m;
		while (m--) {
			cin >> prev;
			adjl[prev].push_back(i);
			inDeg[i]++;
		}
	}
	queue<int> que;
	for (int i = 0; i < n; i++) {
		if (inDeg[i] == 0) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int current = que.front();
		que.pop();
		result.push_back(current);
		for (int next : adjl[current]) {
			inDeg[next]--;
			if (inDeg[next] == 0) {
				que.push(next);
			}
		}
	}
	for (int r : result) {
		printf("%d ", r);
	}
}