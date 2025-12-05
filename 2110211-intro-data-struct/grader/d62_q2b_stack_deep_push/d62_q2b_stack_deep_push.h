// Stack Deep Push

#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos, const T& value) {
  //write your code here
  std::stack<T> tmp;
  while (!this->empty() && pos--) {
    tmp.push(this->top());
    this->pop();
  }
  this->push(value);
  while (!tmp.empty()) {
    this->push(tmp.top());
    tmp.pop();
  }
}

#endif
