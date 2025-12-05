// Queue Free Space

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long mCap = 1, mSize = 0;
	while (n--) {
		int a, k;
		cin >> a >> k;
		if (a) {
			mSize -= k;
		} else {
			mSize += k;
			while (mCap < mSize) {
				mCap *= 2;
			}
		}
	}
	cout << mCap - mSize;
}