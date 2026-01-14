// Heap Node Relation

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << "a and b are the same node\n";
			continue;
		}
		int aa = a, bb = b;
		while (aa > 0 && aa != b) {
			aa = (aa - 1) / 2;
		}
		if (aa == b) {
			cout << "b is an ancestor of a\n";
			continue;
		}
		while (bb > 0 && bb != a) {
			bb = (bb - 1) / 2;
		}
		if (bb == a) {
			cout << "a is an ancestor of b\n";
			continue;
		}
		cout << "a and b are not related\n";
	}
}