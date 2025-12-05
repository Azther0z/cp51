// Orders Stack

#ifndef _STUDENT_H_INCLUDE_
#define _STUDENT_H_INCLUDE_

#include "stack.h"
//You may include here

template<typename T>
void CP::stack<T>::push(const T &value) {
  //You can write your code below here
  ensureCapacity(mSize + 1);
  size_t i = 0;
  for (; i < mSize; i++) {
    if (mData[i] < value) {
      break;
    }
  }
  for (int j = mSize; j > i; j--) {
    mData[j] = mData[j - 1];
  }
  mData[i] = value;
  mSize++;
  return ;
}

template <typename T>
void CP::stack<T>::pop() {
  //Do not modify this line
  if (size() == 0) throw std::out_of_range("index of out range") ;
  //You can write your code below here
  mSize--;
  return ;
}

#endif
