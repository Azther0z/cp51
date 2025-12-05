// List Check
// Hard
// I don't even know how this passed
// Changing order of if's will break everything

#ifndef __STUDENT_H__
#define __STUDENT_H__


template <typename T>
bool CP::list<T>::check() {
  //your code here
  size_t count = 0;
  for (node* ptr = mHeader->next; ptr != mHeader; ptr = ptr->next, count++) {
    if (ptr == NULL) {
      return false;
    }
    if (ptr->next == NULL || ptr->prev == NULL) {
      return false;
    }
    if (ptr != ptr->prev->next) {
      return false;
    }
    if (ptr != ptr->next->prev) {
      return false;
    }
  }
  if (mHeader->next->prev != mHeader || mHeader->prev->next != mHeader) {
    return false;
  }
  if (count != mSize) {
    return false;
  }
  return true;
}


#endif
