// Binary Search Tree Split
// Hard

#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT, MappedT, CompareT> result;
  node *current = mRoot;
  node *origin = NULL;
  node *split = NULL;
  while (current != NULL) {
    if (compare(current->data.first, val) >= 0) { // Take the current node and its right subtree to split tree
      result.child_link(split, current->data.first) = current; // Link latest node in split tree to current node
      current->parent = split; // Cut old connection and update parent
      split = current; // Point to latest node
      current = current->left; // Move to subtree
      split->left = NULL; // Cut old connection
    } else { // Keep the current node and its left subtree to original tree
      child_link(origin, current->data.first) = current; // Link latest node in original tree to current node
      current->parent = origin; // Cut old connection and update parent
      origin = current; // Point to latest node
      current = current->right; // Move to right subtree
      origin->right = NULL; // Cut old connection
    }
  }
  if (origin == NULL) { // Edge case that take whole original tree
    mRoot = NULL;
  }
  return result;
}

#endif
