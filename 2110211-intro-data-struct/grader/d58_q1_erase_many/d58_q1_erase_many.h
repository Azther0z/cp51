// Erase many

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  CP::vector<T> tmp, pos2;
  auto it = pos.begin();
  for (int i = 0; i < this->size(); i++) {
    if (it != pos.end() && i == *it) {
      it++;
      continue;
    }
    tmp.push_back((*this)[i]);
  }
  *this = tmp;
}

#endif
