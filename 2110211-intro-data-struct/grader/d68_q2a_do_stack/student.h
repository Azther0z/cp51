// Do Stack

#ifndef _STUDENT_H_INCLUDE_
#define _STUDENT_H_INCLUDE_

#include "stack.h"

template<typename T>
void CP::stack<T>::push(const T &value) {
  //You can write your code below here
  ensureCapacity(mSize + 1);
  aux_stack_1.push({0, value});
  mData[mSize] = value;
  mSize++;
  while (!aux_stack_2.empty()) {
    aux_stack_2.pop();
  }
  return ;
}

template <typename T>
void CP::stack<T>::pop() {
  //Do not modify this line
  if (size() == 0) throw std::out_of_range("index of out range") ;
  //You can write your code below here
  aux_stack_1.push({1, top()});
  mSize--;
  while (!aux_stack_2.empty()) {
    aux_stack_2.pop();
  }
  return ;
}

template <typename T>
void CP::stack<T>::undo() {
  //You can write your code below here
  if (!aux_stack_1.empty()) {
    aux_stack_2.push(aux_stack_1.top());
    if (!aux_stack_1.top().first) {
      mSize--;
    } else {
      mData[mSize] = aux_stack_1.top().second;
      mSize++;
    }
    aux_stack_1.pop();
  }
  return ;
};

template <typename T>
void CP::stack<T>::redo() {
  //You can write your code below here
  if (!aux_stack_2.empty()) {
    aux_stack_1.push(aux_stack_2.top());
    if (!aux_stack_2.top().first) {
      mData[mSize] = aux_stack_2.top().second;
      mSize++;
    } else {
      mSize--;
    }
    aux_stack_2.pop();
  }
  return ;
}

#endif