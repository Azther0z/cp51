// Heap Equality

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>

template <typename T, typename Comp >
bool CP::priority_queue<T, Comp>::operator==(const CP::priority_queue<T, Comp> &other) const {

  //write your code here
  if (mSize != other.mSize) {
    return false;
  }
  std::vector<T> a(mSize), b(other.mSize);
  for (size_t i = 0; i < mSize; i++) {
    a[i] = mData[i];
    b[i] = other.mData[i];
  }
  sort(a.begin(), a.end(), mLess);
  sort(b.begin(), b.end(), other.mLess);
  for (size_t i = 0; i < mSize; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true; // you can change this line
}

#endif
