// Vector Count Distinct

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <set>

template <typename T>
size_t CP::vector<T>::count_distinct(CP::vector<T>::iterator a, CP::vector<T>::iterator b) {
    // Write your code here
    std::set<T> st;
    for (auto it = a; it != b; it++) {
        st.insert(*it);
    }
    return st.size();
}

#endif