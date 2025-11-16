// List Remove All

#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  //write your code here
  node *current = mHeader->next;
  while (current != mHeader) {
    node *tmp = current->next;
    if (current->data == value) {
      current->prev->next = current->next;
      current->next->prev = current->prev;
      delete current;
      mSize--;
    }
    current = tmp;
  }
}

#endif
