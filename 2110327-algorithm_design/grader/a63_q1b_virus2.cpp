// Virus 2

#include <bits/stdc++.h>
using namespace std;

int countOne(vector<int>::iterator left, vector<int>::iterator right) {
	int result = 0;
	for (auto it = left; it != right; it++) {
		result += *it;
	}
	return result;
}

// dnc(l,r) = dnc(l,mid)&dnc(mid,r)
bool dnc(int l, int r, vector<int>& dna) {
	if (r - l == 2) {
		return true;
	}
	int mid = l + (r - l) / 2;
	if (abs(countOne(dna.begin() + l, dna.begin() + mid) - countOne(dna.begin() + mid, dna.begin() + r)) <= 1) {
		return dnc(l, mid, dna) && dnc(mid, r, dna);
	}
	return false;
}

int main() {
	int n, k;
	cin >> n >> k;
	while (n--) {
		vector<int> dna(1 << k);
		for (int i = 0; i < 1 << k; i++) {
			cin >> dna[i];
		}
		cout << (dnc(0, 1 << k, dna) ? "yes\n" : "no\n");
	}
}