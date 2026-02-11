// Horse Racing
// Trick

#include <bits/stdc++.h>
using namespace std;

// perField = 2
// Round Robin Tournament (wikipedia)
void solve1(int fieldAmount, vector<vector<int>>& result) {
	int totalAmount = 2 * fieldAmount;
	vector<int> vec(totalAmount);
	for (int i = 0; i < totalAmount; i++) {
		vec[i] = i + 1;
	}
	for (int i = 0; i < totalAmount - 1; i++) {
		vector<int> tmp;
		tmp.push_back(vec[0]);
		tmp.push_back(vec[1]);
		for (int j = 0; j < (totalAmount - 1) / 2; j++) {
			tmp.push_back(vec[2 + j]);
			tmp.push_back(vec[totalAmount - 1 - j]);
		}
		result.push_back(tmp);
		int last = vec[1];
		for (int j = 1; j + 1 < totalAmount; j++) {
			vec[j] = vec[j + 1];
		}
		vec[totalAmount - 1] = last;
	}
}

// fieldAmount = 2
// Recursively select combination of {perField} horses out of total {fieldAmount*perField}
void solve2(int index, int size, vector<bool>& used, int perField, vector<vector<int>>& result) {
	if (size == perField) {
		vector<int> left, right;
		for (int i = 1; i <= 2 * perField; i++) {
			if (!used[i]) {
				left.push_back(i);
			} else {
				right.push_back(i);
			}
		}
		for (int i = 0; i < perField; i++) {
			left.push_back(right[i]);
		}
		result.push_back(left);
		return;
	}
	if (index > 2 * perField) {
		return;
	}
	// Somehow, this line is necessary
	if (perField - size > 2 * perField - index) {
		return;
	}
	used[index] = true;
	solve2(index + 1, size + 1, used, perField, result);
	used[index] = false;
	solve2(index + 1, size, used, perField, result);
}

int main() {
	int fieldAmount, perField;
	cin >> fieldAmount >> perField;
	vector<vector<int>> result;
	if (perField == 2) {
		solve1(fieldAmount, result);
	} else if (fieldAmount == 2) {
		vector<bool> used(2 * perField + 1, false);
		solve2(1, 0, used, perField, result);
	}
	cout << result.size() << endl;
	for (vector<int> r : result) {
		for (int i : r) {
			cout << i << ' ';
		}
		cout << endl;
	}
}