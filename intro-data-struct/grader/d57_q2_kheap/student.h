// 4-Ary Heap

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T, typename Comp >
void CP::priority_queue<T, Comp>::fixUp(size_t idx) {
	while (idx > 0 && mLess(mData[(idx - 1) / 4], mData[idx])) {
		std::swap(mData[(idx - 1) / 4], mData[idx]);
		idx = (idx - 1) / 4;
	}
}

template <typename T, typename Comp >
void CP::priority_queue<T, Comp>::fixDown(size_t idx) {
	size_t next = 4 * idx + 1;
	for (int i = 1; i <= 4; i++) {
		if (4 * idx + i < mSize && mData[4 * idx + i] > mData[next]) {
			next = 4 * idx + i;
		}
	}
	while (next < mSize && mData[next] > mData[idx]) {
		std::swap(mData[next], mData[idx]);
		idx = next;
		next = 4 * idx + 1;
		for (int i = 1; i <= 4; i++) {
			if (4 * idx + i < mSize && mData[4 * idx + i] > mData[next]) {
				next = 4 * idx + i;
			}
		}
	}
}

#endif

