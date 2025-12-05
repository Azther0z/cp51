// Vector Block Swap

#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if (a > b) {
    std::swap(a, b);
  }
  if (a < this->begin() || b < this->begin()) {
    return false;
  }
  if (a >= this->end() || b >= this->end() || a + m - 1 >= this->end() || b + m - 1 >= this->end()) {
    return false;
  }
  if (b - a < m) {
    return false;
  }
  if (m <= 0) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    std::swap(*(a + i), *(b + i));
  }
  return true;
}

#endif
