#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> target_pos_by_color[7];

class State {
  public:
    string b;
    int ei, ej;
    int g, h;
    string path;

    State() {}

    State(string _b, int _ei, int _ej, int _g, string _path) {
        b = _b;
        ei = _ei;
        ej = _ej;
        g = _g;
        path = _path;
        h = get_h();
    }

    int get_h() {
        int total_h = 0;
        for (int col = 1; col <= 6; col++) {
            for (int p1 : target_pos_by_color[col]) {
                int r1 = p1 / n, c1 = p1 % n;
                int min_cost = 1e9;
                for (int i = 0; i < n * n; i++) {
                    if (b[i] == col) {
                        int r2 = i / n, c2 = i % n;
                        int cost = abs(r1 - r2) + abs(c1 - c2);
                        if (cost < min_cost) min_cost = cost;
                    }
                }
                total_h += min_cost;
            }
        }
        return total_h;
    }

    bool operator<(const State& o) const {
        return g + h > o.g + o.h;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> n)) return 0;

    string start_b(n * n, 0);
    int start_ei = -1, start_ej = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v; cin >> v;
            if (v == -1) {
                start_b[i * n + j] = 0;
                start_ei = i;
                start_ej = j;
            } else {
                start_b[i * n + j] = v;
            }
        }
    }

    for (int i = 1; i <= n - 2; i++) {
        for (int j = 1; j <= n - 2; j++) {
            int v; cin >> v;
            target_pos_by_color[v].push_back(i * n + j);
        }
    }

    priority_queue<State> pq;
    State init(start_b, start_ei, start_ej, 0, "");

    pq.push(init);
    unordered_set<string> vis;
    vis.insert(init.b);

    int dr[] = { -1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char move_char[] = {'D', 'U', 'R', 'L'};

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        if (cur.h == 0) {
            cout << cur.path << "S\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cur.ei + dr[i];
            int nc = cur.ej + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                string nxt_b = cur.b;
                swap(nxt_b[cur.ei * n + cur.ej], nxt_b[nr * n + nc]);

                if (vis.find(nxt_b) == vis.end()) {
                    vis.insert(nxt_b);
                    State nxt(nxt_b, nr, nc, cur.g + 1, cur.path + move_char[i]);
                    pq.push(nxt);
                }
            }
        }
    }
    return 0;
}
