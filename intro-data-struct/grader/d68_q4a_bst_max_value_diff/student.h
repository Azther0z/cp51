// BST Max Value Difference

#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
#include <queue>

template <typename KeyT, typename MappedT, typename CompareT>
MappedT CP::map_bst<KeyT, MappedT, CompareT>::helper(node *n) {
  // You MAY write code in this function
}

template <typename KeyT, typename MappedT, typename CompareT>
MappedT CP::map_bst<KeyT, MappedT, CompareT>::max_value_diff() {
  // Write your code here
  std::queue<node*> que;
  que.push(mRoot);
  MappedT result = -1;
  while (!que.empty()) {
    node* current = que.front();
    que.pop();
    if (current == NULL) {
      continue;
    }
    if (current->left != NULL && current->right != NULL) {
      if (current->left->data.second < current->right->data.second) {
        MappedT tmp = current->right->data.second - current->left->data.second;
        if (tmp > result) {
          result = tmp;
        }
      } else {
        MappedT tmp = current->left->data.second - current->right->data.second;
        if (tmp > result) {
          result = tmp;
        }
      }
    }
    que.push(current->left);
    que.push(current->right);
  }
  return result;
}

/*
 * Roses are red
 * Violets are blue
 * Your BST knowledge will certainly see you through
 * The problem is set to be solvable and fair
 * Just think carefully, and the solution is there!
 */

#endif
