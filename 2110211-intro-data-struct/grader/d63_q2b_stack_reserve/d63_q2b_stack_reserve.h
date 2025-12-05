// Stack Reserve Compare

#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    size_t a = this->mCap - this->mSize;
    size_t b = other.mCap - other.mSize;
    if (a < b) {
        return -1;
    }
    if (a == b) {
        return 0;
    }
    return 1;
}

#endif
