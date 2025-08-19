// Auction

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a;
	cin >> n >> m >> a;
	vector<int> itemAmount(n+1);
	for(int i=1;i<=n;i++){
		cin >> itemAmount[i];
	}
	multiset<pair<int,int>> ms[n+1];
	map<pair<int,int>,int> buyList;
	while(a--){
		string op;
		cin >> op;
		if(op=="B"){
			int user,item,price;
			cin >> user >> item >> price;
			buyList[{user,item}] = price;
		}
		else if(op=="W"){
			int user,item;
			cin >> user >> item;
			buyList[{user,item}] = 0;
		}
	}
	for(auto x:buyList){
		ms[x.first.second].insert({x.second,x.first.first});
	}
	vector<vector<int>> result(m+1,vector<int>());
	for(int i=1;i<=n;i++){
		for(auto it=ms[i].rbegin();it!=ms[i].rend()&&itemAmount[i];it++){
			if(it->first!=0){
				result[it->second].push_back(i);
				itemAmount[i]--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(!result[i].size()){
			cout << "NONE\n";
			continue;
		}
		sort(result[i].begin(),result[i].end());
		for(auto r:result[i]){
			cout << r << ' ';
		}
		cout << endl;
	}
}