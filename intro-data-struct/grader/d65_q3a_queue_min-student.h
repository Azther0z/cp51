// Queue Min Element

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos, Comp comp) const {
  //your code here
  T result;
  for (auto x : pos) {
    if (x < mSize) {
      result = mData[(mFront + x) % mCap];
      break;
    }
  }
  for (auto x : pos) {
    if (x < mSize && comp(mData[(mFront + x) % mCap], result)) {
      result = mData[(mFront + x) % mCap];
    }
  }
  //should return something
  return result;
}

#endif
