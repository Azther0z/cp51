// Double Stack
// Hard

#ifndef __STUDENT_H_
#define __STUDENT_H_

// #include "stack.h"
template <typename T>
void balance(std::stack<T> &a, std::stack<T> &b) {
	std::stack<T> tmp;
	for (int i = 0; i < a.size() / 2; i++) {
		tmp.push(a.top());
		a.pop();
	}
	while (!a.empty()) {
		b.push(a.top());
		a.pop();
	}
	while (!tmp.empty()) {
		a.push(tmp.top());
		tmp.pop();
	}
}

template <typename T>
void CP::stack<T>::pop() {
	// modify method here
	if (stack_a.empty()) {
		balance(stack_b, stack_a);
	}
	stack_a.pop();
}

template <typename T>
const T& CP::stack<T>::top() {
	// modify method here
	if (stack_a.empty()) {
		balance(stack_b, stack_a);
	}
	return stack_a.top();
}

template <typename T>
const T& CP::stack<T>::bottom() {
	// write your code here
	if (stack_b.empty()) {
		balance(stack_a, stack_b);
	}
	return stack_b.top();
}

template <typename T>
void CP::stack<T>::push_bottom(const T& element) {
	// write your code here
	stack_b.push(element);
}

template <typename T>
void CP::stack<T>::pop_bottom() {
	// write your code here
	if (stack_b.empty()) {
		balance(stack_a, stack_b);
	}
	stack_b.pop();
}
#endif