// Journey
// pi:openai-codex/gpt-5.5
#include <bits/stdc++.h>
using namespace std;

// Let middle cities 2..N-1 be indexed 0..m-1.
// dp[S][i] = max score to start at city 1, visit exactly middle set S, and end at city i+2.
// Base: dp[{i}][i] = w[1][i+2]; initialize unreachable states to negative infinity.
// Transition: dp[S U {j}][j] = max_i(dp[S][i] + w[i+2][j+2]); ans = max_i dp[All][i] + w[i+2][N].

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<long long>> w(n, vector<long long>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> w[i][j];
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (n == 2) {
		cout << w[0][1];
		return 0;
	}

	int m = n - 2;
	int total = 1 << m;
	const long long NEG_INF = -(1LL << 60);
	vector<vector<long long>> dp(total, vector<long long>(m, NEG_INF));
	for (int i = 0; i < m; i++) dp[1 << i][i] = w[0][i + 1];

	for (int mask = 1; mask < total; mask++) {
		for (int last = 0; last < m; last++) {
			long long cur = dp[mask][last];
			if (cur == NEG_INF) continue;
			for (int nxt = 0; nxt < m; nxt++) {
				if (mask & (1 << nxt)) continue;
				int nmask = mask | (1 << nxt);
				dp[nmask][nxt] = max(dp[nmask][nxt], cur + w[last + 1][nxt + 1]);
			}
		}
	}

	long long ans = NEG_INF;
	int full = total - 1;
	for (int last = 0; last < m; last++) {
		ans = max(ans, dp[full][last] + w[last + 1][n - 1]);
	}
	cout << ans;
	return 0;
}
