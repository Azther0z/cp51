// Vector Punch
#include <iostream> 
#include <vector> 
 
using namespace std; 
 
vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) { 
  //write some code here 
  // cout << *(it-k) << ' ' << *(it+k+1) << endl;
  v.erase((it-k)-v.begin()<0?v.begin():it-k,(it+k+1)-v.begin()>=v.size()?v.end():it+k+1);
  return v;
  //don’t forget to return something 
} 
 
int main() { 
  int n,j,k; 
  cin >> n >> j >> k; 
  vector<string> v(n); 
  for (int i = 0;i < n;i++) { 
    cin >> v[i]; 
  } 
 
  cout << "Result after punch" << endl; 
  vector<string> result = punch(v, v.begin() + j, k); 
  for (auto &x : result) { 
    cout << x << endl; 
  } 
}