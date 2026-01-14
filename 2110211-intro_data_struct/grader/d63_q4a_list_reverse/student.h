// List Reverse

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  //write your code here
  if (a == b) {
    return a;
  }
  node *current = a.ptr;
  node *before = a.ptr->prev;
  node *first = a.ptr;
  node *last = b.ptr->prev;
  while (current != b.ptr) {
    node *tmp = current->next;
    std::swap(current->next, current->prev);
    current = tmp;
  }
  before->next = last;
  last->prev = before;
  first->next = b.ptr;
  b.ptr->prev = first;
  return iterator(before->next);
}

#endif
