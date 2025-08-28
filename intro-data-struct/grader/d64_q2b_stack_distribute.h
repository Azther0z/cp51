#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
  std::vector<std::vector<T>> result(k);
  int jdx = this->mSize - 1;
  int vSize = this->mSize / k;
  int remainder = this->mSize % k;
  for (size_t i = 0; i < k; i++) {
    std::vector<T> tmp(vSize);
    for (int j = 0; j < vSize; j++) {
      tmp[j] = this->mData[jdx];
      jdx--;
    }
    if (remainder > 0) {
      remainder--;
      tmp.push_back(this->mData[jdx]);
      jdx--;
    }
    result[i] = tmp;
  }
  return result;
}
#endif
