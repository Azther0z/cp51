// Graph Coloring

#include <bits/stdc++.h>
using namespace std;

bool validColor(int current, int c, vector<int> &color, vector<vector<int>> &adjl) {
	for (int next : adjl[current]) {
		if (color[next] == c) {
			return false;
		}
	}
	return true;
}

bool paint(int current, int maxColor, vector<int> &color, vector<vector<int>> &adjl, int n) {
	if (current == n) {
		return true;
	}
	for (int c = 1; c <= maxColor; c++) {
		if (validColor(current, c, color, adjl)) {
			color[current] = c;
			if (paint(current + 1, maxColor, color, adjl, n)) {
				return true;
			}
			color[current] = 0;
		}
	}
	return false;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> adjl(n);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	for (int maxColor = 1; maxColor <= n; maxColor++) {
		vector<int> color(n, 0);
		if (paint(0, maxColor, color, adjl, n)) {
			cout << maxColor;
			break;
		}
	}
}