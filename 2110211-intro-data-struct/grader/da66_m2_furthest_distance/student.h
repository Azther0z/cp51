// Furthest Distance

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux) {
	// You MAY use this function
	if (n == NULL) {
		return -1;
	}
	int leftHeight = my_recur(n->left, aux);
	int rightHeight = my_recur(n->right, aux);
	aux = std::max(aux, 2 + leftHeight + rightHeight);
	return 1 + std::max(leftHeight, rightHeight);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
	int result = -1;
	my_recur(mRoot, result);
	return result;
}

#endif
