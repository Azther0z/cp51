// Tiling
// Hard

#include <bits/stdc++.h>
using namespace std;

class Command {
  public:
	int type, x, y;
	Command(int nt, int nx, int ny) {
		type = nt;
		x = nx;
		y = ny;
	}
};

void dnc(int l, int startX, int startY, int missX, int missY, vector<Command> &result) {
	int midX = startX + l / 2;
	int midY = startY + l / 2;
	if (l == 2) {
		if (missX < midX && missY < midY) {
			result.push_back(Command(0, startX, startY));
		}
		if (missX < midX && missY >= midY) {
			result.push_back(Command(2, startX, startY));
		}
		if (missX >= midX && missY < midY) {
			result.push_back(Command(1, startX, startY));
		}
		if (missX >= midX && missY >= midY) {
			result.push_back(Command(3, startX, startY));
		}
	} else {
		if (missX < midX && missY < midY) {
			result.push_back(Command(0, midX - 1, midY - 1));
			dnc(l / 2, startX, startY, missX, missY, result);
			dnc(l / 2, startX, midY, midX - 1, midY, result);
			dnc(l / 2, midX, startY, midX, midY - 1, result);
			dnc(l / 2, midX, midY, midX, midY , result);
		}
		if (missX < midX && missY >= midY) {
			result.push_back(Command(2, midX - 1, midY - 1));
			dnc(l / 2, startX, startY, midX - 1, midY - 1, result);
			dnc(l / 2, startX, midY, missX, missY, result);
			dnc(l / 2, midX, startY, midX, midY - 1, result);
			dnc(l / 2, midX, midY, midX, midY , result);
		}
		if (missX >= midX && missY < midY) {
			result.push_back(Command(1, midX - 1, midY - 1));
			dnc(l / 2, startX, startY, midX - 1, midY - 1, result);
			dnc(l / 2, startX, midY, midX - 1, midY, result);
			dnc(l / 2, midX, startY, missX, missY, result);
			dnc(l / 2, midX, midY, midX, midY , result);
		}
		if (missX >= midX && missY >= midY) {
			result.push_back(Command(3, midX - 1, midY - 1));
			dnc(l / 2, startX, startY, midX - 1, midY - 1, result);
			dnc(l / 2, startX, midY, midX - 1, midY, result);
			dnc(l / 2, midX, startY, midX, midY - 1, result);
			dnc(l / 2, midX, midY, missX, missY , result);
		}
	}
}

int main() {
	int l, x, y;
	cin >> l >> x >> y;
	vector<Command> result;
	dnc(l, 0, 0, x, y, result);
	printf("%d\n", result.size());
	for (Command r : result) {
		printf("%d %d %d\n", r.type, r.x, r.y);
	}
}