// Interval Count

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> vec(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}
	sort(vec.begin(),vec.end());
	while(m--){
		int q;
		cin >> q;
		auto l = lower_bound(vec.begin(),vec.end(),q-k);
		auto r = upper_bound(vec.begin(),vec.end(),q+k);
		cout << r-l << ' ';
	}
}