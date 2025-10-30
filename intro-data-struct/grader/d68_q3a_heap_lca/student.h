// Heap Lowest Common Ancestor

#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library or write any helper funtion here
#include "priority_queue.h"

template <typename T, typename Comp >
size_t CP::priority_queue<T, Comp>::lca(size_t p, size_t q) const {
  /*
        Secure the subtasks instead of chasing full marks.
        With best intentions, from dungeonowner :)
  */
  while (p > 0 && q > 0) {
    if (p < q) {
      q = (q - 1) / 2;
    } else if (p > q) {
      p = (p - 1) / 2;
    } else if (p == q) {
      return p;
    }
  }
  return 0;
}

#endif
