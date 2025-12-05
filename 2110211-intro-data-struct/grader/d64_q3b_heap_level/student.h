// Heap Level

#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"
#include <queue>

template <typename T, typename Comp >
std::vector<T> CP::priority_queue<T, Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> r;
  std::queue<std::pair<size_t, size_t>> que;
  que.push({0, 0});
  while (!que.empty()) {
    size_t current = que.front().first;
    size_t level = que.front().second;
    que.pop();
    if (level == k) {
      r.push_back(mData[current]);
      continue;
    }
    if (2 * current + 1 < mSize) {
      que.push({2 * current + 1, level + 1});
    }
    if (2 * current + 2 < mSize) {
      que.push({2 * current + 2, level + 1});
    }
  }
  sort(r.begin(), r.end(), mLess);
  reverse(r.begin(), r.end());
  return r;
}

#endif

