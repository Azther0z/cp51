// Normal Puzzle

#include <bits/stdc++.h>
using namespace std;

vector<vector<short>> source;
vector<vector<short>> target;
vector<pair<short, short>> sourcePos, targetPos;

class State {
  public:
    bool isReverse;
    int cost;
    int heu;
    vector<vector<short>> board;
    string path;
    State(bool nisReverse, int ncost, vector<vector<short>> nboard, string npath) {
        isReverse = nisReverse;
        cost = ncost;
        board = nboard;
        path = npath;
        heu = 0;
        if (!isReverse) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board.size(); j++) {
                    if (board[i][j] != 1 + i * board.size() + j) {
                        int ti = (board[i][j] - 1) / board.size();
                        int tj = (board[i][j] - 1) % board.size();
                        heu += abs(ti - i) + abs(tj - j);
                    }
                }
            }
        } else {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board.size(); j++) {
                    if (board[i][j] != source[i][j]) {
                        int ti = sourcePos[board[i][j]].first;
                        int tj = sourcePos[board[i][j]].second;
                        heu += abs(ti - i) + abs(tj - j);
                    }
                }
            }
        }
    }
    bool completed() {
        if (!isReverse) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board.size(); j++) {
                    if (board[i][j] != 1 + i * board.size() + j) {
                        return false;
                    }
                }
            }
            return true;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != source[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    void display() {
        cout << isReverse << ' ' << cost << endl << path;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    }
    bool operator<(const State &other) const {
        return heu > other.heu;
    }
};

int main() {
    int n;
    cin >> n;
    source.resize(n, vector<short>(n));
    target.resize(n, vector<short>(n));
    sourcePos.resize(n * n + 1);
    targetPos.resize(n * n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> source[i][j];
            target[i][j] = 1 + n * i + j;
            sourcePos[source[i][j]] = {i, j};
            targetPos[1 + n * i + j] = {i, j};
        }
    }
    priority_queue<State> que;
    map<vector<vector<short>>, short> visited;
    map<vector<vector<short>>, pair<int, string>> stateMap;
    visited[target] = 1;
    // visited[source]=1;
    // que.push(State(0,0,source,""));
    que.push(State(1, 0, target, ""));
    while (!que.empty()) {
        State c = que.top();
        que.pop();
        // c.display();
        if (c.completed()) {
            cout << c.cost << endl << c.path;
            return 0;
        }
        for (int i = 0; i < n; i++) {
            vector<vector<short>> tmp(c.board);
            short x = tmp[i][0];
            for (int j = 0; j + 1 < n; j++) {
                tmp[i][j] = tmp[i][j + 1];
            }
            tmp[i][n - 1] = x;
            if (!visited[tmp]) {
                visited[tmp] = (c.isReverse ? 2 : 1);
                string npath = (!c.isReverse ? c.path + to_string(i + 1) + "L" + "\n" : to_string(i + 1) + "R" + "\n" + c.path);
                // stateMap[tmp]={c.cost+1,npath};
                State next(c.isReverse, c.cost + 1, tmp, npath);
                // if(next.heu<c.heu){
                que.push(next);
                // }
            }
        }
        for (int i = 0; i < n; i++) {
            vector<vector<short>> tmp(c.board);
            short x = tmp[0][i];
            for (int j = 0; j + 1 < n; j++) {
                tmp[j][i] = tmp[j + 1][i];
            }
            tmp[n - 1][i] = x;
            if (!visited[tmp]) {
                visited[tmp] = (c.isReverse ? 2 : 1);
                string npath = (!c.isReverse ? c.path + to_string(i + 1) + "U" + "\n" : to_string(i + 1) + "D" + "\n" + c.path);
                // stateMap[tmp]={c.cost+1,npath};
                State next(c.isReverse, c.cost + 1, tmp, npath);
                // if(next.heu<c.heu){
                que.push(next);
                // }
            }
        }
        for (int i = 0; i < n; i++) {
            vector<vector<short>> tmp(c.board);
            short x = tmp[i][n - 1];
            for (int j = n - 1; j > 0; j--) {
                tmp[i][j] = tmp[i][j - 1];
            }
            tmp[i][0] = x;
            if (!visited[tmp]) {
                visited[tmp] = (c.isReverse ? 2 : 1);
                string npath = (!c.isReverse ? c.path + to_string(i + 1) + "R" + "\n" : to_string(i + 1) + "L" + "\n" + c.path);
                // stateMap[tmp]={c.cost+1,npath};
                State next(c.isReverse, c.cost + 1, tmp, npath);
                // if(next.heu<c.heu){
                que.push(next);
                // }
            }
        }
        for (int i = 0; i < n; i++) {
            vector<vector<short>> tmp(c.board);
            short x = tmp[n - 1][i];
            for (int j = n - 1; j > 0; j--) {
                tmp[j][i] = tmp[j - 1][i];
            }
            tmp[0][i] = x;
            if (!visited[tmp]) {
                visited[tmp] = (c.isReverse ? 2 : 1);
                string npath = (!c.isReverse ? c.path + to_string(i + 1) + "D" + "\n" : to_string(i + 1) + "U" + "\n" + c.path);
                // stateMap[tmp]={c.cost+1,npath};
                State next(c.isReverse, c.cost + 1, tmp, npath);
                // if(next.heu<c.heu){
                que.push(next);
                // }
            }
        }
    }
}