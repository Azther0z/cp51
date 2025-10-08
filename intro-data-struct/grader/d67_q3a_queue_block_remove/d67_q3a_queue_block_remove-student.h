// Queue Block Remove

#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::queue<T>::block_remove(size_t from, size_t to) {
    // Write your code here
    if (mSize - to <= from) {
        for (int i = mFront + from; i < mFront + mSize; i++) {
            mData[i % mCap] = mData[(i + to - from + 1) % mCap];
        }
    } else {
        for (size_t i = mFront + from - 1 + mCap; i >= mFront + mCap; i--) {
            mData[(i + to - from + 1) % mCap] = mData[i % mCap];
        }
        mFront += to - from + 1;
    }
    mSize -= to - from + 1;

    return;
}
#endif