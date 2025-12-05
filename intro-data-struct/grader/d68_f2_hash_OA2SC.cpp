// Hash OA2SC

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    while (n--) {
        int b, h;
        cin >> b >> h;
        mp[h]++;
    }
    for (auto x : mp) {
        cout << x.first << ": " << x.second << "\n";
    }
}