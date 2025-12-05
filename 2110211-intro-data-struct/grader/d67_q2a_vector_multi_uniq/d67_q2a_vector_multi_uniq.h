// Vector Multi Unique

#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
// #include "vector.h"
#include <set>
#include <algorithm>

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
  // Write code here
  std::set<T> st;
  sort(itrs.begin(), itrs.end());
  auto jt = itrs.begin();
  CP::vector<T> tmp;
  for (auto it = this->begin(); it != this->end(); it++) {
    if (jt != itrs.end() && it == *jt) {
      if (st.find(*it) == st.end()) {
        st.insert(*it);
        tmp.push_back(*it);
      }
      jt++;
      continue;
    }
    tmp.push_back(*it);
  }
  *this = tmp;
}

#endif
