// Vector Unique

#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure

#include <set>
template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  std::set<T> st;
  T *tmp = new T[mSize]();
  size_t i = 0;
  for (auto it = begin(); it != end(); it++) {
    if (st.find(*it) == st.end()) {
      st.insert(*it);
      tmp[i] = *it;
      i++;
    }
  }
  delete[] mData;
  mData = tmp;
  mSize = i;
}

#endif
