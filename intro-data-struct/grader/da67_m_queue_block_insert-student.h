// Queue Block Insert

#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element) {
	// write your code here
	ensureCapacity(mSize + m);
	if (p >= mSize - p) {
		mSize += m;
		for (size_t i = mFront + mSize - 1; i >= mFront + p + m; i--) {
			mData[i % mCap] = mData[(i - m) % mCap];
		}
	} else {
		mSize += m;

		for (size_t i = mFront; i < mFront + p ; i++) {
			mData[(i - m + mCap) % mCap] = mData[i % mCap];
		}
		mFront = (mFront - m + mCap) % mCap;
	}
	for (size_t i = mFront + p; i < mFront + p + m; i++) {
		mData[i % mCap] = element;
	}
}

#endif