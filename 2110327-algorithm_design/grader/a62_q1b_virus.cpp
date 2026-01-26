// Virus

#include <bits/stdc++.h>
using namespace std;

bool dnc(int l, int r, bool reverse, vector<int>& dna) {
	// cout << l << ' ' << r << endl;
	if (r - l == 2) {
		switch (reverse) {
		case false:
			return dna[l] == 0 && dna[l + 1] == 1;
		case true:
			return dna[l] == 1 && dna[l + 1] == 0;
		}
	}
	int mid = l + (r - l) / 2;
	// if current call is already reversed, next reversible (left half) is at right half
	if (reverse) {
		return (dnc(mid, r, 0, dna) || dnc(mid, r, 1, dna)) && dnc(l, mid, reverse, dna);
	}
	return (dnc(l, mid, 0, dna) || dnc(l, mid, 1, dna)) && dnc(mid, r, reverse, dna);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> dna(1 << k);
	while (n--) {
		for (int i = 0; i < 1 << k; i++) {
			cin >> dna[i];
		}
		cout << (dnc(0, 1 << k, false, dna) ? "yes\n" : "no\n");
	}
}