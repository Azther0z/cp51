// Count Value in Map

#ifndef _STUDENT_H_
#define _STUDENT_H_

// you can also include anything else here
#include <algorithm>

std::vector<size_t> count_value(const std::map<long long, int> &data, const std::vector<std::pair<int, int>> &queries) {
  std::vector<size_t> r;
  //write your code here
  std::vector<int> vec;
  for (auto x : data) {
    vec.push_back(x.second);
  }
  sort(vec.begin(), vec.end());
  for (auto q : queries) {
    r.push_back(std::upper_bound(vec.begin(), vec.end(), q.second) - std::lower_bound(vec.begin(), vec.end(), q.first));
  }
  return r;
}

#endif
