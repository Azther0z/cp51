// CUCAS Rating

#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << fixed << setprecision(2);
	int n;
	cin >> n;
	map<string, vector<int>> courses, teachers;
	while (n--) {
		string course, teacher;
		int score;
		cin >> course >> teacher >> score;
		courses[course].push_back(score);
		teachers[teacher].push_back(score);
	}
	for (auto x : courses) {
		int score = 0;
		for (auto y : x.second) {
			score += y;
		}
		cout << x.first << ' ' << (score + 0.0) / x.second.size() << endl;
	}
	for (auto x : teachers) {
		int score = 0;
		for (auto y : x.second) {
			score += y;
		}
		cout << x.first << ' ' << (score + 0.0) / x.second.size() << endl;
	}
}