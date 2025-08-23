// Chocolate Truffle

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long r, c, k;
	cin >> r >> c >> k;
	vector<long long> vec(k);
	for (int i = 0; i < k; i++) {
		long long a, b;
		cin >> a >> b;
		// if(a<1||a>r||b<1||b>c){
		// 	continue;
		// }
		a--;
		b--;
		vec[i] = a * c + b;
	}
	sort(vec.begin(), vec.end());
	// for(auto v:vec){
	// 	cout << v << ' ';
	// }
	cout << endl;
	int q;
	cin >> q;
	while (q--) {
		long long si, sj;
		cin >> si >> sj;
		si--;
		sj--;
		long long start = si * c + sj;
		// cout << start << ' ';
		long long result = 2e18;
		auto it = lower_bound(vec.begin(), vec.end(), start);
		if (it != vec.end()) {
			result = min(result, *it - start);
		}
		result = min(result, vec[0] + r * c - start );
		cout << result << endl;
	}
}