// Sort Position

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> vec(n);
	for(int i=0;i<n;i++){
		cin >> vec[i].first;
		vec[i].first += 1e6;
		vec[i].second = i;
	}
	sort(vec.begin(),vec.end());
	vector<int> result(2e6+1,-1);
	for(int i=0;i<n;i++){
		result[vec[i].second] = i;
	}
	for(int i=0;i<2e6+1;i++){
		if(result[i]==-1){
			continue;
		}
		cout << result[i]+1 << ' ';
	}
}