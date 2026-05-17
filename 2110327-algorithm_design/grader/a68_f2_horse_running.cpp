// Horse Running

#include <bits/stdc++.h>
using namespace std;

// Consider contribution of each runner
// Contribution = P[i]*(k-1) + S[i]*(n-k)
// Contribution = P[i]*k - P[i] + S[i]*n - S[i]*k
// Contribution = k*(P[i]-S[i]) - P[i] + S[i]*n
// Therefore, we should sort the order of runner by difference in P and S

class Runner {
  public:
	int power, stamina;
	bool operator<(const Runner &other) const {
		return power - stamina < other.power - other.stamina;
	}
};

int main() {
	int n;
	cin >> n;
	vector<Runner> runner(n);
	for (int i = 0; i < n; i++) {
		cin >> runner[i].power >> runner[i].stamina;
	}
	sort(runner.begin(), runner.end());
	long long result = 0;
	for (int i = 0; i < n; i++) {
		result += 1LL * runner[i].power * i + 1LL * runner[i].stamina * (n - i - 1);
	}
	cout << result;
}