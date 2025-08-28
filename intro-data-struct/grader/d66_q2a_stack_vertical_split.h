// Stack Vertical Split

#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
// #include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  int jdx = this->size() - 1;
  size_t remainder = this->size() % k;
  size_t nSize = this->size() / k;
  output.resize(k);
  for (int i = 0; i < k; i++) {
    std::stack<T> tmp;
    for (int j = 0; j < nSize; j++) {
      tmp.push(this->mData[jdx]);
      jdx--;
    }
    if (remainder) {
      remainder--;
      tmp.push(this->mData[jdx]);
      jdx--;
    }
    std::stack<T> tmp2;
    while (!tmp.empty()) {
      tmp2.push(tmp.top());
      tmp.pop();
    }
    output[i] = tmp2;
  }
}

#endif
