// Stack Move Insert

#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k, CP::stack<T> &s2, int m) {
  //your code here
  k = std::min(k, int(this->size()));
  m = std::min(m, int(s2.size()));
  CP::stack<T> tmp;
  while (k--) {
    tmp.push(this->top());
    this->pop();
  }
  while (m--) {
    tmp.push(s2.top());
    s2.pop();
  }
  while (!tmp.empty()) {
    this->push(tmp.top());
    tmp.pop();
  }
}
#endif
