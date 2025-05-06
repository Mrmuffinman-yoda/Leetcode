#include <iostream>
#include <vector>

using namespace std;

class MinStack {
 private:
  vector<int> mainStack;
  vector<int> minStack;

 public:
  MinStack() {}

  void push(int val) {
    mainStack.push_back(val);
    int currentMin;
    if (minStack.empty()) {
      currentMin = val;
    } else {
      currentMin = min(minStack.back(), val);
    }
    minStack.push_back(currentMin);
    return;
  }

  void pop() {
    mainStack.pop_back();
    minStack.pop_back();
    return;
  }

  int top() { return mainStack.back(); }

  int getMin() { return minStack.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */