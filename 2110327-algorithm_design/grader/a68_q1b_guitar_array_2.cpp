// Guitar's Array 2

#include <bits/stdc++.h>
using namespace std;

void R(int n, int m, vector<int>& result) {
    if (result.size() == n) {
        for (int r : result) {
            printf("%d ", r);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= m; i++) {
        int current = result.size() - 1;
        if (result.size() >= 2 && result[current] < result[current - 1] && i > result[current]) {
            result.push_back(i);
            R(n, m, result);
            result.pop_back();
        }
        if (result.size() >= 2 && result[current] > result[current - 1] && i < result[current]) {
            result.push_back(i);
            R(n, m, result);
            result.pop_back();
        }
        if (result.size() == 0 || (result.size() == 1 && result[current] != i)) {
            result.push_back(i);
            R(n, m, result);
            result.pop_back();
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> result;
    R(n, m, result);
}