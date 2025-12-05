// Heap K-th

#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T, typename Comp >
T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  size_t sz = std::min((size_t)7, mSize);
  std::vector<T> vec(sz);
  for (size_t i = 0; i < sz; i++) {
    vec[i] = mData[i];
  }
  sort(vec.begin(), vec.end(), mLess);
  return vec[vec.size() - k];
}

#endif
