// Stack from set
// Trick

#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
// #include "d64_q2a_stack_from_set-stack.h"
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first, typename std::set<T>::iterator last) {
  //write your code ONLY here
  CP::stack<T> a;
  for (auto it = first; it != last; it++) {
    a.push(*it);
  }
  this->mData = new T[1]();
  this->mCap = 1;
  this->mSize = 0;
  while (!a.empty()) {
    push(a.top());
    a.pop();
  }
}

#endif
