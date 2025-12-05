// List Longest Palindrome

#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template<typename T>
size_t CP::list<T>::longest_palindrome() {
  int mid = (mSize - 1) / 2;
  node *left = mHeader->next;
  while (mid--) {
    left = left->next;
  }
  node *right = left->next;
  if (mSize % 2 != 0) {
    left = left->prev;
  }
  if (left->data != right->data) {
    return 1;
  }
  int result = (mSize % 2 != 0) ? 1 : 0;
  while (left != mHeader && right != mHeader && left->data == right->data) {
    result += 2;
    left = left->prev;
    right = right->next;
  }
  return result;
}

#endif