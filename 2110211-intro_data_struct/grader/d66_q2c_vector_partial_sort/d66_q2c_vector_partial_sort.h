// Vector Partial Sort

#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything
#include <algorithm>
template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos, CompareT  comp) {
  // Write code here
  // you can compare two data A and B of type T by calling comp(A,B)
  // which return true when A is less than B
  CP::vector<iterator> key;
  CP::vector<T> val;
  for (auto x : pos) {
    key.push_back(x);
    val.push_back(*x);
  }
  std::sort(key.begin(), key.end());
  std::sort(val.begin(), val.end(), comp);
  for (int i = 0; i < key.size(); i++) {
    *(key[i]) = val[i];
  }
}

#endif
