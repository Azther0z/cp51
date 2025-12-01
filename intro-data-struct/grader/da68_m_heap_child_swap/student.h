// Heap Child Swap

#include "priority_queue.h"
#include <utility>

template <typename T, typename Comp>
void CP::priority_queue<T, Comp>::child_swap(size_t k) {
  for (size_t i = 1; i < mSize; i = i << 1) {
    k = 2 * k + 1;
    if (k >= mSize) {
      break;
    }
    for (size_t j = 0; j < i; j++) {
      std::swap(mData[k + j], mData[k + j + i]);
    }
  }
}