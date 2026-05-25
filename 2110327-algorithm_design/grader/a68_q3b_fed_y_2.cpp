// FED-Y 2

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> adjm(n + 1, vector<int>(n + 1, -1e9));
    vector<pair<int, pair<int, int>>> edge(m);
    for (int i = 0; i < m; i++) {
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    }
    vector<int> distance(n + 1, -1e9);
    distance[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto e : edge) {
            if (distance[e.second.first] + e.first > distance[e.second.second]) {
                distance[e.second.second] = distance[e.second.first] + e.first;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << distance[i] << ' ';
    // }
    // cout << endl;
    bool check = true;
    for (auto e : edge) {
        if (distance[e.second.first] + e.first > distance[e.second.second]) {
            check = false;
            break;
        }
    }
    cout << (check ? to_string(distance[t]) : "INFINITY") << endl;
}