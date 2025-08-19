// Min of Max

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> vec(n);
	vector<int> team(m,1);
	multiset<int> power(team.begin(),team.end());
	for(int i=0;i<n;i++){
		cin >> vec[i].first;
	}
	for(int i=0;i<n;i++){
		cin >> vec[i].second;
	}
	for(int i=0;i<n;i++){
		if(team[vec[i].second]<vec[i].first){
			power.erase(power.find(team[vec[i].second]));
			power.insert(vec[i].first);
			team[vec[i].second] = vec[i].first;
		}
		cout << *power.begin() << ' ';	
	}
}