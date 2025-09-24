// Queue Vertical Split

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const {
  // your code here
  int idx = mFront;
  output.resize(k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < mSize / k; j++) {
      output[i].push(mData[idx]);
      idx = (idx + 1) % mCap;
    }
    if (i < mSize % k) {
      output[i].push(mData[idx]);
      idx = (idx + 1) % mCap;
    }
  }
}

#endif
