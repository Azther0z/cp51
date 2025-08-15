#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> a = {0,1,2};
	vector<int> b = {4,5,6};
	a.insert(a.begin()+1,b.begin(),b.end());
	for(auto x:a){
		cout << x << ' ';
	}
}