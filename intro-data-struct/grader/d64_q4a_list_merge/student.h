// List Merge

#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  for (auto it = ls.begin(); it != ls.end(); it++) {
    if (it->mSize == 0) {
      continue;
    }
    node *oldLast = mHeader->prev;
    node *newLast = it->mHeader->prev;
    node *between = it->mHeader->next;

    it->mHeader->next = it->mHeader;
    it->mHeader->prev = it->mHeader;

    oldLast->next = between;
    between->prev = oldLast;

    mHeader->prev = newLast;
    newLast->next = mHeader;

    mSize += it->mSize;
    it->mSize = 0;
  }
}

#endif
