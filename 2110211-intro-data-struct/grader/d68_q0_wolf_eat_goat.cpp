// Wolf Eat Goat

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int d;
    cin >> d;
    while (d--) {
        int x;
        cin >> x;
        auto it = lower_bound(vec.begin(), vec.end(), x);
        int result = 2e9 + 1;
        if (it != vec.end()) {
            result = min(result, abs(*it - x));
        }
        if (it != vec.begin()) {
            it--;
            result = min(result, abs(*it - x));
        }
        cout << result << endl;
    }
}