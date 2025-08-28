// Split stack

#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
// #include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  //should return something
  int idx = 0;
  int jdx = this->mSize - 1;
  std::vector<std::vector<T>> result(k);
  while (jdx >= 0) {
    result[idx % k].push_back(this->mData[jdx]);
    idx++;
    jdx--;
  }
  for (int i = 0; i < k; i++) {
    reverse(result[i].begin(), result[i].end());
  }
  return result;
}

#endif

