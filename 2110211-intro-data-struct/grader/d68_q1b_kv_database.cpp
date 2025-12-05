// KV Database

#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  map<int, set<pair<int, int>>> mp;
  int current = 0;
  while (q--) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    if (mp.find(a) == mp.end()) {
      mp[a].insert({0, -1});
    }
    if (op == 'U') {
      current++;
      mp[a].insert({current, b});
    } else {
      cout << prev(mp[a].upper_bound({b, INT_MAX}))->second << endl;
    }
  }
}