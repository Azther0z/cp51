// Queue Check

#include <bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin >> n;
	while(n--){
		int mFront,mSize,mCap,last,correction;
		cin >> mFront >> mSize >> mCap >> last >> correction;
		if(mFront<mCap&&last<=mCap&&mSize<=mCap&&(mFront+mSize)%mCap==last){
			cout << "OK\n";
		}
		else{
			cout << "WRONG ";
			if(correction==1){
				mFront = (last - mSize + mCap) % mCap;
				cout << mFront;
			}
			else if(correction==2){
				mSize = (mCap + last - mFront) % mCap;
				cout << mSize;
			}
			else if(correction==3){
				mCap = max(mFront+mSize-last,last+1);
				cout << mCap;
			}
			else if(correction==4){
				last = (mFront + mSize) % mCap;
				cout << last;
			}
			cout << endl;
		}
	}
}

// mSize = (mCap + last - mFront) % mCap
// mSize <= mCap