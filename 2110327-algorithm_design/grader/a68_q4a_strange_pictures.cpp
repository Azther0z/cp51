// Strange Pictures

#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int> &current, vector<int> &target, int n) {
    for (int i = 0; i < n * n; i++) {
        if (current[i] && current[i] != target[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> source(k, vector<int>(n * n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n * n; j++) {
            cin >> source[i][j];
        }
    }
    vector<int> target(n * n);
    for (int i = 0; i < n * n; i++) {
        cin >> target[i];
    }
    vector<int> current(n * n, 0);
    vector<int> result;
    for (int i = 0; i < k; i++) {
        vector<int> tmp = current;
        for (int j = 0; j < n * n; j++) {
            tmp[j] |= source[i][j];
        }
        if (valid(tmp, target, n)) {
            current = tmp;
            result.push_back(i + 1);
        }
    }
    bool check = true;
    for (int i = 0; i < n * n; i++) {
        if (current[i] != target[i]) {
            check = false;
            break;
        }
    }
    if (check) {
        cout << result.size() << endl;
        for (int r : result) {
            cout << r << ' ';
        }
    } else {
        cout << -1;
    }
}