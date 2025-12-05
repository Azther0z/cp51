// Imbalance

// Your code here
int getHeight(node *current, int &mostImbalance, KeyT &key) {
    if (current == NULL) {
        return -1;
    }
    int leftHeight = getHeight(current->left, mostImbalance, key);
    int rightHeight = getHeight(current->right, mostImbalance, key);
    int imbalance = abs(leftHeight - rightHeight);
    if (imbalance == mostImbalance && compare(current->data.first, key) == -1) {
        key = current->data.first;
    } else if (imbalance > mostImbalance) {
        mostImbalance = imbalance;
        key = current->data.first;
    }
    int height = 1 + std::max(leftHeight, rightHeight);
    return height;
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    KeyT result = mRoot->data.first;
    int mostImbalance = -1;
    getHeight(mRoot, mostImbalance, result);
    return result;
}
