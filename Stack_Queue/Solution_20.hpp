#ifndef SOLUTION_20
#define SOLUTION_20
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

给出一个只有三种括号的字符串，判断括号的开闭是否合法，
左括号必须有右括号
典型的栈
如果是左括号，入栈，
如果是右括号，看是否能和栈顶元素配对，能则出栈，否则不合法
*/
#include <stack>
#include <string>
#include <vector>
class Solution_20 {
 public:
  bool isValid(std::string s) {
    std::vector<char> p;
    for (int i = 0; i < s.size(); i++) {
      auto c = s[i];
      if (c == '(' || c == '{' || c == '[') {
        p.push_back(c);
      } else {
        char back;
        if (p.size() > 0) {
          back = p.back();
        } else {
          return false;
        }
        if (c == ')' && back == '(') {
          p.pop_back();
        } else if (c == '}' && back == '{') {
          p.pop_back();
        } else if (c == ']' && back == '[') {
          p.pop_back();
        } else {
          return false;
        }
      }
    }
    return p.empty();
  }
};

class Solution_20_bak {
 public:
  bool isValid(std::string const& s) {
    std::string left = "([{";
    std::string right = ")]}";
    std::stack<char> stk;
    for (auto c : s) {
      if (left.find(c) != std::string::npos) {
        stk.push(c);
      } else {
        if (stk.empty() || stk.top() != left[right.find(c)])
          return false;
        else
          stk.pop();
      }
    }
    return stk.empty();
  }
};
#endif