// Queue Remove Many

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include <algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos) {
  // your code here
  std::sort(pos.begin(), pos.end());
  auto it = pos.begin();
  T *tmp = new T[mSize]();
  int j = 0;
  for (int i = 0; i < mSize; i++) {
    if (it == pos.end() || *it != i) {
      tmp[j] = mData[(mFront + i) % mCap];
      j++;
    } else {
      it++;
    }
  }
  delete[] mData;
  mData = tmp;
  mFront = 0;
  mSize = mSize - pos.size();
}

#endif
