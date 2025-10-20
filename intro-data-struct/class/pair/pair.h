#ifndef PAIR_H_INCLUDED
#define PAIR_H_INCLUDED

#include <stdexcept>
#include <iostream>
// #pragma once

namespace CP {

template <typename T1, typename T2>
class pair {
  public:
	T1 first;
	T2 second;

	// copy constructor
	pair(const pair<T1, T2>& a) {
		first = a.first;
		second = a.second;
	}

	// default constructor using list initialize
	pair(): first(), second() {}

	// custom constructor using list initialize
	pair(const T1 &a, const T2 &b): first(a), second(b) {}

	// no destructor

	// copy assignment operator using traditional assignment
	pair<T1, T2>& operator=(const pair<T1, T2> &other) {
		first = other.first;
		second = other.second;
		return *this;
	}

	bool operator==(const pair<T1, T2> &other) {
		return first == other.first && second == other.second;
	}

	bool operator<(const pair<T1, T2> &other)const {
		if (first != other.first) {
			return first < other.first;
		}
		return second < other.second;
	}
};

}

#endif