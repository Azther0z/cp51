// Table without 11

#include <bits/stdc++.h>
using namespace std;

#define MOD 100000007

// R(n,00) = R(n-1,00)+R(n-1,01)+R(n-1,10)
// R(n,01) = R(n-1,00)+R(n-1,10)
// R(n,10) = R(n-1,00)+R(n-1,01)

int main() {
	int n;
	cin >> n;
	int a = 1, b = 1, c = 1;
	for (int i = 2; i <= n; i++) {
		int aTmp = (a + b + c) % MOD;
		int bTmp = (a + c) % MOD;
		int cTmp = (a + b) % MOD;
		a = aTmp;
		b = bTmp;
		c = cTmp;
	}
	cout << (a + b + c) % MOD;
}