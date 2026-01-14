// Vector Range Erase
// Trick

#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
// #include "vector.h"
#include <algorithm>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here
  sort(ranges.begin(), ranges.end());
  auto jt = ranges.begin();
  CP::vector<T> tmp;
  for (auto it = this->begin(); it != this->end(); it++) {
    while (jt != ranges.end() && it >= jt->second) {
      jt++;
    }
    if (jt->first <= it && it < jt->second) {
      continue;
    }
    tmp.push_back(*it);
  }
  *this = tmp;
}

#endif
