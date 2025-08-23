#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int, int> > v) {
  //WRITE YOUR CODE HERE
  //DON"T FORGET TO RETURN THE RESULT
  stack<int> stk;
  for (auto x : v) {
    if (x.first == 0) {
      int b = stk.top();
      stk.pop();
      int a = stk.top();
      stk.pop();
      if (x.second == 0) {
        stk.push(a + b);
      } else if (x.second == 1) {
        stk.push(a - b);
      } else if (x.second == 2) {
        stk.push(a * b);
      } else if (x.second == 3) {
        stk.push(a / b);
      }
    } else if (x.first == 1) {
      stk.push(x.second);
    }
  }
  return stk.top();
}

#endif