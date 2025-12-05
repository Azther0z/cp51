// Network Marketing

#ifndef _CP_NETWORK_MARKETING_INCLUDED_
#define _CP_NETWORK_MARKETING_INCLUDED_

#include <map>
namespace CP {

template <typename T>

class network_marketing {
  public:
	std::map<T, std::pair<T, size_t>> tree;
	network_marketing() {
	}
	size_t count_children(T x) {
		if (tree.find(x) == tree.end()) {
			return 0;
		}
		return tree[x].second - 1;
	}
	void setparent(T child, T parent) {
		if (tree.find(child) == tree.end()) {
			tree[child] = {parent, 1};
		} else {
			tree[child] = {parent, tree[child].second};
		}
		if (tree.find(parent) == tree.end()) {
			tree[parent] = {parent, 1};
		}
		while (tree[parent].first != parent) {
			tree[parent].second += tree[child].second;
			parent = tree[parent].first;
		}
		tree[parent].second += tree[child].second;
	}
};

}
#endif
