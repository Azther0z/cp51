// Saving for Ice Cream

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,start;
	cin >> n >> m >> start;
	vector<pair<int,int>> vec(n);
	vector<int> pref(100001,0);
	for(int i=0;i<n;i++){
		cin >> vec[i].first >> vec[i].second;
		pref[vec[i].first] = vec[i].second;
	}
	pref[0] = start;
	for(int i=1;i<=100000;i++){
		if(pref[i]==0){
			pref[i] = pref[i-1];
		}
	}
	for(int i=1;i<=100000;i++){
		pref[i] += pref[i-1];
	}
	while(m--){
		int p,x;
		cin >> p >> x;
		if(pref[x]<p){
			p += pref[x];
		}
		cout << lower_bound(pref.begin(),pref.end(),p)-pref.begin() << ' ';
	}
}