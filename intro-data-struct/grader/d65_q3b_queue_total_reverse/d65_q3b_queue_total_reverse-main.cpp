#include "d65_q3b_queue_total_reverse-queue.h"
#include "d65_q3b_queue_total_reverse-student.h"
#include <iostream>

int main() {
  CP::queue<int> q;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int element;
    std::cin >> element;
    q.push(element);
  }
  q.reverse();
  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << q.size() << std::endl;
  for (int i = 0; i < n; ++i) {
    int element;
    std::cin >> element;
    q.push(element);
  }
  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}