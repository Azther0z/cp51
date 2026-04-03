// Closest Pair
// Hard

#include <bits/stdc++.h>
using namespace std;

class Point {
  public:
	int x, y;
	Point() {}
	Point(int nx, int ny) {
		x = ny, y = ny;
	}
	bool operator<(const Point &other)const {
		if (x == other.x) {
			return y < other.y;
		}
		return x < other.x;
	}
};

class compY {
  public:
	bool operator()(const Point &a, const Point &b)const {
		return a.y < b.y;
	}
};

int distance(const Point &a, const Point &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int dnc(int l, int r, vector<Point> &point) {
	int result = 1e9;
	if (r - l <= 3) {
		for (int i = l; i < r; i++) {
			for (int j = i + 1; j < r; j++) {
				result = min(result, distance(point[i], point[j]));
			}
		}
		return result;
	}
	int mid = l + (r - l) / 2;
	result = min(dnc(l, mid, point), dnc(mid, r, point));
	vector<Point> strip;
	for (int i = l; i < r; i++) {
		if ((point[i].x - point[mid].x) * (point[i].x - point[mid].x) < result) {
			strip.push_back(point[i]);
		}
	}
	sort(strip.begin(), strip.end(), compY());
	for (int i = 0; i < strip.size(); i++) {
		for (int j = i + 1; j < strip.size() && (strip[i].y - strip[j].y) * (strip[i].y - strip[j].y) < result; j++) {
			result = min(result, distance(strip[i], strip[j]));
		}
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<Point> point(n);
	for (int i = 0; i < n; i++) {
		cin >> point[i].x >> point[i].y;
	}
	sort(point.begin(), point.end());
	cout << dnc(0, n, point);
}