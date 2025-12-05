// Vector Some Move
// Hard
// Trick

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include <vector>
// #include "vector-sm.h"

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
  int idx = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
  if (index == mSize) {
    mData.insert(mData.end(), value);
    aux.push_back(aux.back() + value.size());
    mSize += value.size();
    mCap = aux.back();
    return;
  }
  if (idx != 0) {
    index -= aux[idx - 1];
  }
  mData[idx].insert(mData[idx].begin() + index, value.begin(), value.end());
  if (mData[idx].size() > 100) {
    std::vector<T> tmp(mData[idx].begin() + 100, mData[idx].end());
    mData[idx].resize(100);
    mData.insert(mData.begin() + idx + 1, tmp);
  }
  aux.resize(mData.size());
  for (int i = 0; i < aux.size(); i++) {
    aux[i] = mData[i].size();
    if (i != 0) {
      aux[i] += aux[i - 1];
    }
  }
  mSize += value.size();
  mCap = aux.back();
}
#endif