// Easy Mountain
// Hard

#include <bits/stdc++.h>
using namespace std;

// As 1<=a[i]<=100, optimal solution is to choose latest value of a[i].
// From Pigeonhole Principle, if we look back more than 100 step,
// there will be only unoptimal solution.
// Therefore, we only look back no more than 100 steps
// R(n) = max{R(n-i)+(a[n]+a[n-i])^3|1<=i<=100}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> memo(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 100 && i - j >= 1; j++) {
            memo[i] = max(memo[i], memo[i - j] + (a[i] + a[i - j]) * (a[i] + a[i - j]) * (a[i] + a[i - j]));
        }
    }
    cout << memo[n];
}