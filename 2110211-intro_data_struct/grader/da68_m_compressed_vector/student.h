// Compressed Vector
// Hard

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "compressed_vector.h"
#include <cstdlib>

template <typename T> void CP::CompressedVector<T>::expand(size_t capacity) {
  // write your code here
  T* tmpV = new T[capacity]();
  size_t* tmpL = new size_t[capacity]();
  for (size_t i = 0; i < mSize; i++) {
    tmpV[i] = mDataV[i];
    tmpL[i] = mDataL[i];
  }
  delete[] mDataV;
  delete[] mDataL;
  mDataL = tmpL;
  mDataV = tmpV;
  mCap = capacity;
}

template <typename T>
void CP::CompressedVector<T>::insert(int index, const T &element) {
  // I don't even know how this works.
  if (mSize == 0) {
    ensureCapacity(mSize + 1);
    mDataV[0] = element;
    mDataL[0] = 1;
    mSize++;
    return;
  }
  size_t sum = 0;
  for (size_t i = 0; i < mSize; i++) {
    sum += mDataL[i];
    if (sum > index) {
      if (i != 0 && mDataV[i - 1] == element) {
        mDataL[i - 1]++;
        return;
      }
      if (mDataV[i] == element) {
        mDataL[i]++;
        return;
      }
      ensureCapacity(mSize + 1);
      for (size_t j = mSize; j > i; j--) {
        mDataV[j] = mDataV[j - 1];
        mDataL[j] = mDataL[j - 1];
      }
      mDataV[i] = element;
      mDataL[i] = 1;
      mSize++;
      return;
    }
  }
  if (mDataV[mSize - 1] == element) {
    mDataL[mSize - 1]++;
    return;
  }
  ensureCapacity(mSize + 1);
  mDataV[mSize] = element;
  mDataL[mSize] = 1;
  mSize++;
}

template <typename T> T &CP::CompressedVector<T>::operator[](int index) const {
  // write your code here
  size_t sum = 0;
  for (size_t i = 0; i < mSize; i++) {
    if (sum + mDataL[i] > index) {
      return mDataV[i];
    }
    sum += mDataL[i];
  }
  return mDataV[0];
}

#endif
