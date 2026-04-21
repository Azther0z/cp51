// Tower Defense 2

#include <bits/stdc++.h>
using namespace std;

class Monster {
  public:
	int pos, hp;
	bool operator<(const Monster &other) const {
		return pos < other.pos;
	}
};

int main() {
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	vector<Monster> monster(m);
	for (int i = 0; i < m; i++) {
		cin >> monster[i].pos;
	}
	int result = 0;
	for (int i = 0; i < m; i++) {
		cin >> monster[i].hp;
		result += monster[i].hp;
	}
	sort(monster.begin(), monster.end());
	int monsterIdx = 0, cannonPos = 1, shot = 0;
	while (cannonPos <= n && shot < k && monsterIdx < m) {
		if (monster[monsterIdx].hp == 0) {
			monsterIdx++;
		} else if (abs(monster[monsterIdx].pos - cannonPos) <= w) {
			monster[monsterIdx].hp--;
			shot++;
			cannonPos++;
		} else if (monster[monsterIdx].pos > cannonPos) {
			cannonPos++;
		} else if (monster[monsterIdx].pos < cannonPos) {
			monsterIdx++;
		}
	}
	cout << result - shot;
}