// Food Delivery

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> query(m);
	for(int i=0;i<m;i++){
		cin >> query[i];
	}
	queue<int> a,b;
	vector<int> result;
	result.push_back(0);
	while(n--){
		int op;
		cin >> op;
		if(op==1){
			int price,app;
			cin >> app >> price;
			if(app==1){
				a.push(price);
			}
			else if(app==2){
				b.push(price);
			}
		}
		else if(op==2){
			if(a.empty()){
				result.push_back(b.front()+result.back());
				b.pop();
			}
			else if(b.empty()){
				result.push_back(a.front()+result.back());
				a.pop();
			}
			else if(a.front()<=b.front()){
				result.push_back(a.front()+result.back());
				a.pop();
			}
			else if(a.front()>b.front()){
				result.push_back(b.front()+result.back());
				b.pop();
			}
		}
	}
	for(auto q:query){
		auto it = lower_bound(result.begin(),result.end(),q);
		cout << (it!=result.end()?it-result.begin():-1) << ' ';
	}
}