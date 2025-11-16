// Zuma

#include <bits/stdc++.h>
using namespace std;

void zuma(list<int>::iterator target, list<int> &ls) {
	while (target != ls.begin() && *prev(target) == *target) {
		target = prev(target);
	}
	if (next(target) == ls.end() || next(target, 2) == ls.end()) {
		return;
	}
	if (*target == *next(target) && *next(target) == *next(target, 2)) {
		int tmp = *target;
		while (*target == tmp) {
			target = ls.erase(target);
		}
		if (target != ls.begin() && *target == *prev(target)) {
			zuma(target, ls);
		}
	}
}

int main() {
	int n, k, v;
	cin >> n >> k >> v;
	list<int> ls;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ls.push_back(tmp);
	}
	auto target = ls.insert(next(ls.begin(), k), v);
	zuma(target, ls);
	for (auto i = ls.begin(); i != ls.end(); i++) {
		cout << *i << ' ';
	}
}