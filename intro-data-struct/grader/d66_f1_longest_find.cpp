// Hash Longest Find

#include <bits/stdc++.h>
using namespace std;

class hashTable {
  public:
	int size;
	vector<int> vec;

	hashTable(int n) {
		vec.resize(n, -1);
		size = n;
	}

	void insert(int element) {
		for (int i = 0; i < size; i++) {
			int h = (element + i * i) % size;
			if (vec[h] == -1 || vec[h] == -2) {
				vec[h] = element;
				break;
			}
		}
	}

	void erase(int element) {
		for (int i = 0; i < size; i++) {
			int h = (element + i * i) % size;
			if (vec[h] == -1) {
				break;
			}
			if (vec[h] == element) {
				vec[h] = -2;
				break;
			}
		}
	}

	void longest(int &maxFind, int &maxInsert) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				int h = (i + j * j) % size;
				if (vec[h] == -2 || vec[h] == -1) {
					maxInsert = max(maxInsert, j);
					break;
				}
			}
			for (int j = 0; j < size; j++) {
				int h = (i + j * j) % size;
				if (vec[h] == -1) {
					maxFind = max(maxFind, j);
					break;
				}
			}
		}
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	hashTable hash(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			hash.insert(b);
		} else {
			hash.erase(b);
		}
	}
	int maxInsert = 0, maxFind = 0;
	hash.longest(maxFind, maxInsert);
	cout << maxInsert + 1 << ' ' << maxFind + 1;
}