// FED-Y

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adjl(n + 1);
    while (m--) {
        int a, b, w;
        cin >>  a >> b >> w;
        adjl[a].push_back({b, w});
        adjl[b].push_back({a, w});
    }
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 1});
    vector<long long> distance(n + 1, 1e18);
    distance[1] = 0;
    while (!pq.empty()) {
        long long cd = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if (cd > distance[current]) {
            continue;
        }
        for (pair<int, int> next : adjl[current]) {
            if (cd + next.second < distance[next.first]) {
                pq.push({ -(cd + next.second), next.first});
                distance[next.first] = cd + next.second;
            }
        }
    }
    long long result = 0;
    for (int i = 2; i <= n; i++) {
        result = max(result, distance[i]);
    }
    for (int i = 2; i <= n; i++) {
        printf("%lld\n", result - distance[i]);
    }
}