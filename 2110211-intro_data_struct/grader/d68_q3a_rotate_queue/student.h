// Rotate Queue

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::rotate(int k) {
  // your code here
  if (mSize == 0) {
    return;
  }
  while (k < 0) {
    k += mSize;
  }
  k = k % mSize;
  if (k <= mSize / 2) {
    for (int i = 0; i < k; i++) {
      mData[(mFront + mSize + i) % mCap] = mData[(mFront + i) % mCap];
    }
    mFront = (mFront + k) % mCap;
  } else {
    k = mSize - k;
    for (int i = 1; i <= k; i++) {
      mData[(mFront - i + mCap) % mCap] = mData[(mFront + mSize - i + mCap) % mCap];
    }
    mFront = (mFront - k + mCap) % mCap;
  }
}

#endif

/*
mSize 8
ro(7) = ro(-1)
1 2 3 4 5 6 7 8
8 1 2 3 4 5 6 7
ro(-3) = ro(5)
1 2 3 4 5 6 7 8
6 7 8 1 2 3 4 5
*/