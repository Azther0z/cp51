// Reverse Vector 2

#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v, vector<int>::iterator a, vector<int>::iterator b) {
	//write your code only in this function
	int sz = b - a;
	for (int i = 0; i < sz / 2; i++) {
		int tmp = *(a + i);
		*(a + i) = *(a + sz - i - 1);
		*(a + sz - i - 1) = tmp;
	}
}

int main() {
	//read input
	int n, a, b;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		v.push_back(c);
	}
	cin >> a >> b;
	//call function
	reverse(v, v.begin() + a, v.begin() + b + 1);
	//display content of the vector
	for (auto &x : v) {
		cout << x << " ";
	}
	cout << endl;
}