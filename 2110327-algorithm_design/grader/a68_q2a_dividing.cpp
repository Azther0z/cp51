// Horse Dividing

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    vector<long long> prefix(n), suffix(n);
    for (int i = 0; i < n; i++) {
        prefix[i] = a[i].first;
        if (i != 0) {
            prefix[i] += prefix[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = a[i].first;
        if (i != n - 1) {
            suffix[i] += suffix[i + 1];
        }
    }
    for (int i = n - 1; i - 1 >= 0; i--) {
        if (suffix[i] > prefix[i - 1] && (prefix[i] >= suffix[i + 1])) {
            printf("%d\n", n - i);
            for (int j = i; j < n; j++) {
                printf("%d ", a[j].second);
            }
            return 0;
        }
    }
    // Damn bro, Spica can have all the member while the other team got zero
    // T_T, time wasted
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
}