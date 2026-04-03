// Connection

#include <bits/stdc++.h>
using namespace std;

class State {
  public:
	int i, d;
	State(int ni, int nd) {
		i = ni;
		d = nd;
	}
};

int bfs(int start, vector<vector<int>> &adjl, int n, int k) {
	queue<State> que;
	vector<bool> visited(n, false);
	que.push(State(start, 0));
	visited[start] = true;
	int result = 0;
	while (!que.empty()) {
		State current = que.front();
		que.pop();
		if (current.d <= k) {
			result++;
		}
		if (current.d >= k) {
			continue;
		}
		for (int next : adjl[current.i]) {
			if (!visited[next]) {
				visited[next] = true;
				que.push(State(next, current.d + 1));
			}
		}
	}
	return result;
}

int main() {
	int n, e, k;
	cin >> n >> e >> k;
	vector<vector<int>> adjl(n);
	while (e--) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, bfs(i, adjl, n, k));
	}
	cout << result;
}