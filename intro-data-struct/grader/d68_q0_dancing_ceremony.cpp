// Dancing Ceremony

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        vec[i] -= b;
    }
    sort(vec.begin(),vec.end());
    long long result = 0;
    for(int i=0;i<n;i++){
        int target = (vec[i]>0?0:-vec[i]+1);
        auto it = lower_bound(vec.begin()+i+1,vec.end(),target);
        result += 1LL*(vec.end()-it);
    }
    cout << result;
}
/*
4
3 7 1 4
3 5 4 2
0 2 -3 2
-3 0 2 2
(0,2) (0,2) (2,2)

5
3 6 5 7 9
4 4 1 2 1
-1 2 4 5 8
(-1,2) (-1,4) (-1,5) (-1,8)
(2,4) (2,5) (2,8)
(4,5) (4,8)
(5,8)
*/