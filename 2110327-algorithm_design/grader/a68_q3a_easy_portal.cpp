// Easy Portal

#include <bits/stdc++.h>
using namespace std;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

class State {
  public:
    int i, j, d;
    State(int ni, int nj, int nd) {
        i = ni, j = nj, d = nd;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    int si, sj, ti, tj, bi, bj, wi, wj;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            switch (grid[i][j]) {
            case 'S': si = i, sj = j; break;
            case 'T': ti = i, tj = j; break;
            case 'B': bi = i, bj = j; break;
            case 'W': wi = i, wj = j; break;
            default: break;
            }
        }
    }
    vector<vector<int>> distance(n, vector<int>(m, 1e9));
    distance[si][sj] = 0;
    queue<State> que;
    que.push(State(si, sj, 0));
    while (!que.empty()) {
        State current = que.front();
        que.pop();
        if (current.d > distance[current.i][current.j]) {
            continue;
        }
        if (current.i == bi && current.j == bj) {
            distance[wi][wj] = current.d + 1;
            que.push(State(wi, wj, current.d + 1));
        }
        for (int dir = 0; dir < 4; dir++) {
            int ni = current.i + di[dir];
            int nj = current.j + dj[dir];
            if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[ni][nj] != '#' && current.d + 1 < distance[ni][nj]) {
                distance[ni][nj] = current.d + 1;
                que.push(State(ni, nj, current.d + 1));
            }
        }
    }
    cout << (distance[ti][tj] == 1e9 ? -1 : distance[ti][tj]);
}