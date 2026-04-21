// 0/1 Knapsack with Real Number Weight

#include <bits/stdc++.h>
using namespace std;

class Object {
  public:
	double value, weight;
	bool operator<(const Object& other) const {
		return value / weight > other.value / other.weight;
	}
};

double w, result = 0;
int n;
vector<Object> obj;

double heuristic(int current, double cw) {
	double heu = 0;
	for (int i = current; i < n && cw < w; i++) {
		heu += min(w - cw, obj[i].weight) * obj[i].value / obj[i].weight;
		cw += min(w - cw, obj[i].weight);
	}
	return heu;
}

void dfs(int current, double cv, double cw) {
	if (cw > w) {
		return;
	}
	result = max(result, cv);
	if (current == n) {
		return;
	}
	if (cv + heuristic(current, cw) <= result) {
		return;
	}
	dfs(current + 1, cv + obj[current].value, cw + obj[current].weight);
	dfs(current + 1, cv, cw);
}

int main() {
	cin >> w >> n;
	obj.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> obj[i].value;
	}
	for (int i = 0; i < n; i++) {
		cin >> obj[i].weight;
	}
	sort(obj.begin(), obj.end());
	dfs(0, 0, 0);
	printf("%.4lf", result);
}