// Password

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, l;
	cin >> n >> m >> l;
	set<string> st;
	vector<int> vec(l);
	for (int i = 0; i < l; i++) {
		cin >> vec[i];
	}
	while (n--) {
		string s;
		cin >> s;
		st.insert(s);
	}
	while (m--) {
		string s;
		cin >> s;
		for (int i = 0; i < l; i++) {
			s[i] = ((s[i] - 'a') + vec[i]) % 26 + 'a';
		}
		cout << (st.find(s) != st.end() ? "Match\n" : "Unknown\n");
	}
}