// Insert Many to Vector

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data) {
  //write your code here
  std::sort(data.begin(), data.end());
  CP::vector<T> tmp;
  int idx = 0;
  for (int i = 0; i < this->size(); i++) {
    if (idx != data.size() && data[idx].first == i) {
      tmp.push_back(data[idx].second);
      idx++;
    }
    tmp.push_back((*this)[i]);
  }
  while (idx < data.size()) {
    tmp.push_back(data[idx].second);
    idx++;
  }
  *this = tmp;
}

#endif
