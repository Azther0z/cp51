// Card Battle

#include <bits/stdc++.h>
using namespace std;

int battle(multiset<int> &ms, int m){
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		while(k--){
			int power;
			cin >> power;
			auto it = ms.upper_bound(power);
			if(it==ms.end()){
				return i;
			}
			ms.erase(it);
		}
	}
	return m+1;
}

int main(){
	int n,m;
	cin >> n >> m;
	multiset<int> ms;
	while(n--){
		int tmp;
		cin >> tmp;
		ms.insert(tmp);
	}
	cout << battle(ms,m);
}