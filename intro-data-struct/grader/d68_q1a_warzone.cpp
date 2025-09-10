// Warzone

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    multiset<pair<int, int>> ms;
    while (q--) {
        int l, r;
        cin >> l >> r;
        r++;
        auto it = ms.lower_bound({l, -1});
        while (it != ms.end() && it->first <= r) {
            n += it->second - it->first;
            r = max(r, it->second);
            it = ms.erase(it);
        }
        if (it != ms.begin()) {
            it--;
            if (it->second >= l) {
                n += it->second - it->first;
                l = min(l, it->first);
                r = max(r, it->second);
                ms.erase(it);
            }
        }
        ms.insert({l, r});
        n -= r - l;
        cout << n << endl;
    }
}
/*
10 3
5 7
1 4
6 6
*/