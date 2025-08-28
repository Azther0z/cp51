// Wasted Space

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int result = 1;
	while (result < n) {
		result =  result << 1;
	}
	cout << result - n;
}