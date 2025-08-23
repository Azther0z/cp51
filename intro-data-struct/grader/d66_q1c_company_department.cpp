// Company Department

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, string> employee;
	set<string> department;
	for (int i = 0; i < n; i++) {
		string e, d;
		cin >> e >> d;
		employee[e] = d;
		department.insert(d);
	}
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			string e, d;
			cin >> e >> d;
			employee[e] = d;
			department.insert(d);
		} else if (op == 2) {
			string source, target;
			cin >> source >> target;
			department.erase(source);
			for (auto &e : employee) {
				if (e.second == source) {
					e.second = target;
				}
			}
			department.insert(target);
		}
	}
	map<string, set<string>> result;
	for (auto d : department) {
		result[d] = set<string>();
	}
	for (auto e : employee) {
		result[e.second].insert(e.first);
	}
	for (auto r : result) {
		cout << r.first << ": ";
		for (auto e : r.second) {
			cout << e << ' ';
		}
		cout << endl;
	}
}