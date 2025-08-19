// Inside Interval

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> vec(n);
	for(int i=0;i<n;i++){
		cin >> vec[i].first >> vec[i].second;
	}
	sort(vec.begin(),vec.end());
	while(m--){
		int q;
		cin >> q;
		auto it = upper_bound(vec.begin(),vec.end(),make_pair(q,INT_MAX));
		if(it!=vec.begin()){
			it--;
		}
		cout << (it->first<=q&&q<=it->second?1:0) << ' ';
	}
}