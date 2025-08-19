// Wall Paint
// Hard

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> action(m);
	for(int i=0;i<m+m;i++){
		int x,c,d;
		cin >> x >> c >> d;
		c--;
		if(d==0){
			action[c].first = x;
		}
		else if(d==1){
			action[c].second = x;
		}
	}
	set<pair<int,int>> st;
	st.insert({0,n+1});
	for(int i=0;i<m;i++){
		auto it = st.lower_bound({action[i].first,0});
		if(it->first<=action[i].second){
			it--;
			if(it->first<action[i].first&&action[i].second<it->second){
				st.insert({action[i].first,action[i].second});
				continue;
			}	
		}
	}
	int result = 0;
	stack<pair<int,int>> stk;
	for(auto p:st){
		while(!stk.empty()&&p.first>stk.top().second){
			// cout << 'p' << stk.top().first << ' ' << stk.top().second << endl;
			stk.pop();
		}
		stk.push(p);
		result = max(result,int(stk.size()));
		cout << p.first << ' ' << p.second << ' ' << stk.size() << endl;
	}
	cout << result-1;
}