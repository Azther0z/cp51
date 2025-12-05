// Restaurant

#include <bits/stdc++.h>
using namespace std;

class Chef {
 public:
	int a, t;
	bool operator<(const Chef other)const {
		if (a != other.a) {
			return a > other.a;
		}
		return t > other.t;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	priority_queue<Chef> pq;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		pq.push({0, vec[i]});
	}
	int time = 0;
	while (m--) {
		if (pq.top().a > time) {
			time = pq.top().a;
		}
		pq.push({pq.top().a + pq.top().t, pq.top().t});
		pq.pop();
		cout << time << endl;
	}
}