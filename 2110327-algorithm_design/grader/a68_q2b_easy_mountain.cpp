// Easy Mountain
// Hard

#include <bits/stdc++.h>
using namespace std;

// R(a) = max{R(i)+(i+a)^3|1<=i<=100}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> memo(101, -1);
    long long result = 0;
    memo[a[1]] = 0;
    for (int i = 2; i <= n; i++) {
        long long tmp = 0;
        for (int j = 1; j <= 100; j++) {
            if (memo[j] != -1) {
                tmp = max(tmp, memo[j] + (a[i] + j) * (a[i] + j) * (a[i] + j));
            }
        }
        memo[a[i]] = max(memo[a[i]], tmp);
        result = max(result, memo[a[i]]);
    }
    cout << result;
}