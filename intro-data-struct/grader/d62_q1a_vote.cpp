// Vote

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	map<string,int> mp;
	while(n--){
		string s;
		cin >> s;
		mp[s]++;
	}
	vector<int> vec;
	for(auto x:mp){
		vec.push_back(x.second);
	}
	sort(vec.begin(),vec.end());
	cout << vec[max(0,int(vec.size())-k)];
}