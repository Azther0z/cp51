// List Replace

void replace(const T& x, list<T>& y) {
  //write your code here
  node *current = mHeader->next;
  while (current != mHeader) {
    node *tmp = current->next;
    if (current->data == x) {
      iterator it = erase(iterator(current));
      for (auto yy = y.begin(); yy != y.end(); yy++) {
        insert(it, *yy);
      }
    }
    current = tmp;
  }
}
