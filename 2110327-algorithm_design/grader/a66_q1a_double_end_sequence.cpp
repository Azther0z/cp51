// Maximum Double End Sequence Sum

#include <bits/stdc++.h>
using namespace std;

// int main() {
// 	// mp[i] contains vector of index that has value i
// 	map<int, vector<int>> mp;
// 	int result = -1e9;
// 	int n;
// 	cin >> n;
// 	vector<int> arr(n + 1, 0), prefixSum(n + 1, 0);
// 	for (int i = 1; i <= n; i++) {
// 		cin >> arr[i];
// 		prefixSum[i] = arr[i] + prefixSum[i - 1];
// 	}
// 	// similar to Kadane's
// 	// createNew (use subarray sum between last two index with value i)
// 	// concatOld (use subarray sum between last index and first index with value i)
// 	for (int i = 1; i <= n; i++) {
// 		mp[arr[i]].push_back(i);
// 		if (mp[arr[i]].size() == 3) {
// 			int createNew = prefixSum[mp[arr[i]][2]] - prefixSum[mp[arr[i]][1]];
// 			int concatOld = prefixSum[mp[arr[i]][2]] - prefixSum[mp[arr[i]][0]];
// 			if (createNew > concatOld) {
// 				mp[arr[i]].erase(mp[arr[i]].begin());
// 			} else {
// 				mp[arr[i]].erase(mp[arr[i]].begin() + 1);
// 			}
// 		}
// 		if (mp[arr[i]].size() > 0) {
// 			result = max(result, prefixSum[*(mp[arr[i]].end() - 1)] - prefixSum[(*mp[arr[i]].begin()) - 1]);
// 		}
// 	}
// 	cout << result;
// }

int main() {
	int result = -1e9;
	int n;
	cin >> n;
	vector<int> arr(n + 1, 0), prefixSum(n + 1, 0);
	// To find maximum subarray ended at i,
	// we can find prefix - min_prefix = max_subarray
	map<int, int> minPrefix;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		prefixSum[i] = prefixSum[i - 1] + arr[i];
		if (minPrefix.count(arr[i]) == 0) {
			minPrefix[arr[i]] = prefixSum[i - 1];
		} else {
			minPrefix[arr[i]] = min(minPrefix[arr[i]], prefixSum[i - 1]);
		}
		result = max(result, prefixSum[i] - minPrefix[arr[i]]);
	}
	cout << result;
}