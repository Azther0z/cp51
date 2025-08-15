// Most Frequent Word

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	map<string,int> mp;
	while(n--){
		string s;
		cin >> s;
		mp[s]++;
	}
	int mx = 0;
	string result = "";
	for(auto x:mp){
		if(x.second >= mx){
			mx = x.second;
			result = x.first;
		}
	}
	cout << result << ' ' << mx;
}