// Vector Mirror

#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  ensureCapacity(this->mSize * 2);
  for (int i = 0; i < this->mSize; i++) {
    this->mData[mSize * 2 - 1 - i] = this->mData[i];
  }
  mSize = mSize + mSize;
}

#endif
