// Drainage
// pi:openai-codex/gpt-5.5
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l;
	cin >> n >> l;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p.begin(), p.end());

	int ans = 0, cover = -1;
	for (int x : p) {
		if (x > cover) {
			ans++;
			cover = x + l - 1;
		}
	}
	cout << ans;
	return 0;
}
