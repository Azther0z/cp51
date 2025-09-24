// Vector No Move

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  //your code here
  auto it = std::upper_bound(aux.begin(), aux.end(), idx);
  if (it == aux.begin()) {
    return mData[0][idx];
  }
  return mData[it - aux.begin()][idx - *prev(it)];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  //your code here
  //you MAY need this function
  if (!aux.empty()) {
    aux.push_back(aux.back() + mData.back().size());
  } else {
    aux.push_back(mData.back().size());
  }
}

#endif
