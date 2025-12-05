// Heap Lowest Common Ancestor 2

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"

template <typename T, typename Comp >
size_t CP::priority_queue<T, Comp>::lca(size_t p, size_t q) {
  while (p != q) {
    if (mLess(q, p)) {
      p = (p - 1) / 2;
    } else if (mLess(p, q)) {
      q = (q - 1) / 2;
    }
  }
  mData[p] = mData[mSize - 1];
  mSize--;
  if (2 * p + 1 < mSize && 2 * p + 2 < mSize && (mLess(mData[p], mData[2 * p + 1]) || mLess(mData[p], mData[2 * p + 2]))) {
    fixDown(p);
  }
  if (p > 0 && mLess(mData[(p - 1) / 2], mData[p])) {
    fixUp(p);
  }
  return p;
}

#endif
