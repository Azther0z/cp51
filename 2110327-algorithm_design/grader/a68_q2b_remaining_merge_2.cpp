// Remaining Merge 2
// Hard

#include <bits/stdc++.h>
using namespace std;

string s;
int result = 0;

pair<int, int> dnc(int l, int r) {
    if (l == r) {
        return {s[l] == '0', s[l] == '1'};
    }
    int m = (l + r) / 2;
    pair<int, int> left = dnc(l, m);
    pair<int, int> right = dnc(m + 1, r);
    // printf("%d %d\n",l,r);
    // printf("%d %d %d\n",left.first,left.second,left.result);
    // printf("%d %d %d\n",right.first,right.second,right.result);
    if (left.first == 0 && right.first == 0) {
        result += right.second;
    } else if (left.second == 0 && right.second == 0) {
        result += right.first;
    } else if (left.second != 0 && right.second == 0) {
        result += left.second;
    } else if (left.second == 0 && right.second != 0) {
        result += right.first + right.second;
    } else {
        result += right.second;
    }
    return {left.first + right.first, left.second + right.second};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n >> s;
    dnc(0, n - 1);
    cout  << result << endl;
    // cout << s;
}