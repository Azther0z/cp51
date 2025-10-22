// Heap Height

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T, typename Comp >
int CP::priority_queue<T, Comp>::height() const {
  //write your code here
  if (mSize == 0) {
    return -1;
  }
  int current = mSize - 1;
  int h = 0;
  while (current > 0) {
    current = (current - 1) >> 1;
    h++;
  }
  return h;
}

#endif

