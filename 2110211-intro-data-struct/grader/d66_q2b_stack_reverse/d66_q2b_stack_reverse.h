// Stack Reverse

#ifndef __STUDENT_H_
#define __STUDENT_H_

// #include "stack.h"

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last) {
	// write your code here
	if (last < first) {
		return;
	}
	CP::stack<T> a, b;
	for (int i = 0; i < first && !this->empty(); i++) {
		a.push(this->top());
		this->pop();
	}
	for (int i = 0; i < last - first + 1 && !this->empty(); i++) {
		b.push(this->top());
		this->pop();
	}
	while (!b.empty()) {
		a.push(b.top());
		b.pop();
	}
	while (!a.empty()) {
		this->push(a.top());
		a.pop();
	}
}

#endif
