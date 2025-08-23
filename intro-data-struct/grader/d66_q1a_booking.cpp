// Booking

#include <bits/stdc++.h>
using namespace std;

bool valid(multiset<pair<string,string>> &ms, vector<pair<string,string>> &vec){
	for(auto v:vec){
		if(ms.find(v)==ms.end()){
			return false;
		}
	}
	return true;
}

int main(){
	int n,m;
	cin >> n >> m;
	multiset<pair<string,string>> ms;
	while(n--){
		string a,b;
		cin >> a >> b;
		ms.insert({a,b});
	}
	while(m--){
		int k;
		cin >> k;
		vector<pair<string,string>> vec(k);
		for(int i=0;i<k;i++){
			cin >> vec[i].first >> vec[i].second;
		}
		if(valid(ms,vec)){
			for(auto v:vec){
				ms.erase(ms.find(v));
			}
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}