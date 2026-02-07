// Thanos

#include <bits/stdc++.h>
using namespace std;

long long dnc(int l, int r, int noAvengerCost, int haveAvengerCost, vector<int>& avenger) {
	int length = r - l + 1;
	int avengerCount = upper_bound(avenger.begin(), avenger.end(), r) - lower_bound(avenger.begin(), avenger.end(), l);
	if (avengerCount == 0) {
		return noAvengerCost;
	}
	long long result = (long long)avengerCount * length * haveAvengerCost;
	if (length >= 2) {
		return min(result, dnc(l, l + (r - l) / 2, noAvengerCost, haveAvengerCost, avenger) + dnc(l + (r - l) / 2 + 1, r, noAvengerCost, haveAvengerCost, avenger));
	}
	// cout << l << ' ' << r << ' ' << result << endl;
	return result;
}

int main() {
	int p, k, noAvengerCost, haveAvengerCost;
	cin >> p >> k >> noAvengerCost >> haveAvengerCost;
	vector<int> avenger(k);
	for (int i = 0; i < k; i++) {
		cin >> avenger[i];
	}
	sort(avenger.begin(), avenger.end());
	cout << dnc(1, 1 << p, noAvengerCost, haveAvengerCost, avenger);
}