// Queue Multi Count

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T, size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
    std::map<T, size_t> mp;
    for (auto x : k) {
        mp[x] = 0;
    }
    for (int i = 0; i < mSize; i++) {
        if (mp.find(mData[(mFront + i) % mCap]) != mp.end()) {
            mp[mData[(mFront + i) % mCap]]++;
        }
    }
    std::vector<std::pair<T, size_t>> result;
    for (auto x : k) {
        result.push_back({x, mp[x]});
    }
    return result;
}

#endif
