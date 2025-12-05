// Range Insert

#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
  //write your code here
  int size = last - first;
  int pos = position - this->begin();
  this->ensureCapacity(this->size() + size);
  // std::cout << size << ' ' << int(pos);
  for (int i = mSize - 1; i >= pos; i--) {
    this->mData[i + size] = this->mData[i];
  }
  for (int i = 0; i < size; i++) {
    this->mData[i + pos] = *(first + i);
  }
  this->mSize += size;
}

#endif
