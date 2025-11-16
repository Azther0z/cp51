// List Extract

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value, iterator a, iterator b, CP::list<T>& output) {
  //write your code here
  node *current = a.ptr;
  while (current != b.ptr) {
    node *tmp = current->next;
    if (current->data == value) {
      current->prev->next = current->next;
      current->next->prev = current->prev;
      mSize--;
      output.mHeader->next->prev = current;
      current->next = output.mHeader->next;
      output.mHeader->next = current;
      current->prev = output.mHeader;
      output.mSize++;
    }
    current = tmp;
  }
}

#endif
