// Hiatus

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	set<pair<int,int>> st;
	while(n--){
		int a,b;
		cin >> a >> b;
		st.insert({a,b});
	}
	while(m--){
		int a,b;
		cin >> a >> b;
		auto it = st.lower_bound({a,b});
		if(*it==make_pair(a,b)){
			cout << "0 0 ";
		}
		else if(it!=st.begin()){
			it--;
			cout << it->first << ' ' << it->second << ' ';
		}
		else{
			cout << "-1 -1 ";
		}
	}
}