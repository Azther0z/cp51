// AVL Balance Value

#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_avl.h"
#include <vector>

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_avl<KeyT, MappedT, CompareT>::my_recur(node* node, iterator it, std::vector<size_t> &balance) const {
    // You may need this function
    if (node == NULL) {
        return;
    }
    int leftHeight = (node->left != NULL) ? node->left->height : -1;
    int rightHeight = (node->right != NULL) ? node->right->height : -1;
    if (leftHeight - rightHeight == -1) {
        balance[2]++;
    } else if (leftHeight - rightHeight == 0) {
        balance[1]++;
    } else {
        balance[0]++;
    }
    my_recur(node->left, it, balance);
    my_recur(node->right, it, balance);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_avl<KeyT, MappedT, CompareT>::my_recur_2(node* node, iterator it, std::vector<size_t> &balance) const {
    // You may need this function

}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<size_t> CP::map_avl<KeyT, MappedT, CompareT>::balance_values(iterator it) const  {
    // Write your code here
    std::vector<size_t> balance(3, 0);
    my_recur(it.ptr, it, balance);
    return balance;
}

#endif