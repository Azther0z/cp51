// Hash Next Cost

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "unordered_map.h"

namespace CP {

template <typename KeyT,
          typename MappedT,
          typename HasherT,
          typename EqualT>
size_t CP::unordered_map<KeyT, MappedT, HasherT, EqualT>::next_cost(iterator it) {
    //Write code here
    if (it == end()) {
        return 0;
    }
    size_t bucketIdx = hash_to_bucket(it->first);
    ValueIterator findIdx = find_in_bucket(mBuckets[bucketIdx], it->first);
    if (findIdx != mBuckets[bucketIdx].end()) {
        findIdx++;
        if (findIdx != mBuckets[bucketIdx].end()) {
            return 1;
        }
    }
    size_t cost = 1;
    bucketIdx++;
    while (bucketIdx != mBuckets.size() && mBuckets[bucketIdx].size() == 0) {
        cost++;
        bucketIdx++;
    }
    return cost + 1;
}
}

#endif


