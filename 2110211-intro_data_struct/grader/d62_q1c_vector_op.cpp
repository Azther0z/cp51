// Vector Operation

#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	vector<int> vec;
	while (q--) {
		string op;
		cin >> op;
		if (op == "pb") {
			int x;
			cin >> x;
			vec.push_back(x);
		}
		if (op == "sa") {
			sort(vec.begin(), vec.end());
		}
		if (op == "sd") {
			sort(vec.begin(), vec.end(), greater<int>());
		}
		if (op == "r") {
			reverse(vec.begin(), vec.end());
		}
		if (op == "d") {
			int i;
			cin >> i;
			vec.erase(vec.begin() + i);
		}
	}
	for (auto v : vec) {
		cout << v << ' ';
	}
}