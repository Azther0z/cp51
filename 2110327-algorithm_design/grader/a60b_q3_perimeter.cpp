// Perimeter

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, e, k;
	cin >> n >> e >> k;
	vector<vector<int>> adjl(n + 1);
	while (e--) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	queue<pair<int, int>> que;
	vector<int> distance(n + 1, 1e9);
	que.push({0, 0});
	distance[0] = 0;
	int result = 0;
	while (!que.empty()) {
		int cd = que.front().first;
		int current = que.front().second;
		que.pop();
		if (cd > distance[current]) {
			continue;
		}
		if (cd == k) {
			result++;
		}
		for (int next : adjl[current]) {
			if (cd + 1 < distance[next]) {
				distance[next] = cd + 1;
				que.push({cd + 1, next});
			}
		}
	}
	cout << result;
}