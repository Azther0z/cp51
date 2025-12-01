// List Wrong Prev

#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template<typename T>
size_t CP::list<T>::fix_wrong() {
  size_t count = 0;
  for (node* ptr = mHeader->next; ptr != mHeader; ptr = ptr->next) {
    if (ptr->next->prev != ptr) {
      ptr->next->prev = ptr;
      count++;
    }
  }
  if (mHeader->next->prev != mHeader) {
    mHeader->next->prev = mHeader;
    count++;
  }
  return count;
}

#endif