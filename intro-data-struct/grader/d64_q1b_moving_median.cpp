// Moving Median

#include <bits/stdc++.h>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	int n, w;
	cin >> n >> w;
	vector<int> vec(n);
	multiset<int> minHeap;
	multiset<int> maxHeap;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		maxHeap.insert(vec[i]);
		if (maxHeap.size() + minHeap.size() < w + 1) {
			continue;
		}
		if (minHeap.count(vec[i - w - 1])) {
			minHeap.erase(minHeap.find(vec[i - w - 1]));
		} else if (maxHeap.count(vec[i - w - 1])) {
			maxHeap.erase(maxHeap.find(vec[i - w - 1]));
		}
		// cout << vec[i-w-1] << endl;
		while (minHeap.size() && *minHeap.begin() <= *maxHeap.rbegin()) {
			maxHeap.insert(*minHeap.begin());
			minHeap.erase(minHeap.begin());
		}
		while (minHeap.size() != maxHeap.size() + 1) {
			minHeap.insert(*maxHeap.rbegin());
			maxHeap.erase(maxHeap.find(*maxHeap.rbegin()));
		}
		cout << *minHeap.begin() << ' ';
	}
}