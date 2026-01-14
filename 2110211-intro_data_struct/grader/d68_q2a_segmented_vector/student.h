// Segmented Vector

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "segmented_vector.h"
template <typename T>
CP::SegmentedVector<T>::~SegmentedVector() {
    // TODO: Write your code here
    for (int i = 0; i < mCap; i++) {
        delete [] mData[i];
    }
    delete [] mData;
}
template <typename T>
void CP::SegmentedVector<T>::expand(size_t capacity) {
    // TODO: Write your code here
    T** tmp = new T*[capacity]();
    for (int i = 0; i < capacity; i++) {
        tmp[i] = new T[blockSize]();
    }
    for (int i = 0; i < mSize; i++) {
        tmp[i / blockSize][i % blockSize] = mData[i / blockSize][i % blockSize];
    }
    for (int i = 0; i < mCap; i++) {
        delete [] mData[i];
    }
    delete [] mData;
    mCap = capacity;
    mData = tmp;
}
template <typename T>
void CP::SegmentedVector<T>::insert(int index, const T& element) {
    // TODO: Write your code here
    ensureCapacity(((mSize + 1) + (blockSize - 1)) / blockSize);
    for (int i = mSize; i > index; i--) {
        mData[i / blockSize][i % blockSize] = mData[(i - 1) / blockSize][(i - 1) % blockSize];
    }
    mData[index / blockSize][index % blockSize] = element;
    mSize++;
}
template <typename T>
T& CP::SegmentedVector<T>::operator[](int index) const {
    // TODO: Write your code here
    return mData[index / blockSize][index % blockSize];
}
#endif

/*
b5 6/5 = 1 (6+5)/5=2 (10+5)/2=3 (6+4)/5 = 2
b3 (3+2)/3 = 1 (4+2)/3=2 ()
*/