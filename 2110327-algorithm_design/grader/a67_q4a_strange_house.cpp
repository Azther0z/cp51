// Strange House

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adjl;

class State {
  public:
	string color;
	int node;
	State(string ncolor, int nnode) {
		color = ncolor;
		node = nnode;
	}
};

int main() {
	cin >> n >> m;
	adjl.resize(2 * n + 2);
	while (m--) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	string source = " ", target = " ";
	for (int i = 1; i <= n; i++) {
		source += '1';
		target += '2';
	}
	for (int i = 1; i <= n; i++) {
		source += '2';
		target += '1';
	}
	source += '0';
	target += '0';
	map<string, pair<int, int>> parent;
	map<string, int> visited;
	queue<State> que;
	que.push(State(source, 2 * n + 1));
	int count = 0;
	while (!que.empty()) {
		State current = que.front();
		que.pop();
		count++;
		if (count > 93000) {
			break;
		}
		if (current.color == target) {
			vector<int> result;
			while (current.color != source) {
				result.push_back(parent[current.color].second);
				swap(current.color[parent[current.color].first], current.color[parent[current.color].second]);
			}
			reverse(result.begin(), result.end());
			printf("%d\n", result.size());
			for (int p : result) {
				printf("%d ", p);
			}
			return 0;
		}
		for (int next : adjl[current.node]) {
			swap(current.color[next], current.color[current.node]);
			if (visited[current.color] == 0) {
				visited[current.color] = 1;
				parent[current.color] = {current.node, next};
				que.push(State(current.color, next));
			}
			swap(current.color[next], current.color[current.node]);
		}
	}
	cout << -1;
}
