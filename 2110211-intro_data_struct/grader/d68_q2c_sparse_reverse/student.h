// Sparse Vector Reverse

#include "sparse_vector.h"
#include <vector>

template<typename T>
void CP::sparse_vector<T>::range_reserve(int left, int right) {
	std::vector<std::pair<int, T>> vec;
	auto it = mData.lower_bound(left);
	while (it != mData.end() && it->first <= right) {
		vec.push_back({right - (it->first - left), it->second});
		it = mData.erase(it);
	}
	for (auto x : vec) {
		mData[x.first] = x.second;
	}
}