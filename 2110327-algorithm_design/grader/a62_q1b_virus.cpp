// Virus

#include <bits/stdc++.h>
using namespace std;

bool dnc(int l, int r, vector<int>& dna) {
	// cout << l << ' ' << r << endl;
	if (r - l == 2) {
		return dna[l] == 0 && dna[l + 1] == 1;
	}
	int mid = l + (r - l) / 2;
	if (!dnc(mid, r, dna)) {
		return false;
	}
	if (dnc(l, mid, dna)) {
		return true;
	}
	reverse(dna.begin() + l, dna.begin() + mid);
	if (dnc(l, mid, dna)) {
		return true;
	}
	reverse(dna.begin() + l, dna.begin() + mid);
	return false;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> dna(1 << k);
	while (n--) {
		for (int i = 0; i < 1 << k; i++) {
			cin >> dna[i];
		}
		cout << (dnc(0, 1 << k, dna) ? "yes\n" : "no\n");
	}
}