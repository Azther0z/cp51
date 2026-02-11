// Guitar's Array

#include <bits/stdc++.h>
using namespace std;

bool valid(int l, int r, int x, vector<int>& vec) {
    for (int i = l; i < r; i++) {
        if (vec[i] != x) {
            return false  ;
        }
    }
    return true;
}

bool dnc(int l, int r, int x, vector<int>& vec) {
    if (r - l == 1) {
        return vec[l] == x;
    }
    int mid = l + (r - l) / 2;
    return (valid(l, mid, x, vec) && dnc(mid, r, x + 1, vec)) || (dnc(l, mid, x + 1, vec) && valid(mid, r, x, vec));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, x;
        cin >> k >> x;
        vector<int> vec(1 << k);
        for (int i = 0; i < 1 << k; i++) {
            cin >> vec[i];
        }
        cout << (dnc(0, 1 << k, x, vec) ? "YES" : "NO") << endl;
    }
}