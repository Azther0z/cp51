// List Split

#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it, size_t pos) {
  //write your code here
  CP::list<T> result;
  if (it == end()) {
    return result;
  }
  if (it == begin()) {
    result.mSize = mSize;
    mSize = 0;

    result.mHeader->prev = mHeader->prev;
    result.mHeader->prev->next = result.mHeader;

    result.mHeader->next = it.ptr;
    result.mHeader->next->prev = result.mHeader;

    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    return result;
  }
  result.mSize = mSize - pos;
  mSize = pos;

  result.mHeader->prev = mHeader->prev;
  result.mHeader->next = it.ptr;
  mHeader->prev = it.ptr->prev;

  result.mHeader->prev->next = result.mHeader;
  result.mHeader->next->prev = result.mHeader;

  mHeader->prev->next = mHeader;
  return result;
}

#endif
