#ifndef SOLUTION_32
#define SOLUTION_32
/*
Given a string containing just the characters '(' and ')', find the length of
the longest valid (well-formed) parentheses substring.
给出只有()的字符串，找出里面最长合法的长度
(())、()()、这种是合法的，长度为4

两遍扫描法，记录深度和括号其实位置下标
------
用栈保存左括号（出现的位置，
如果遇到右括号），
如果栈不为空，即有左括号可以与之配对，可以出栈，
并且如果出栈后栈为空，求len和当前位置到起始合法位置中的较大值
否则求当前位置与新栈顶元素之间的距离
如果栈为空，那这个）就是非法的位置，后移一位
*/
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
//)))()()()((((()))((((((((((()))))))) ()(((())))
//   3 5 7      13 12 11               0 5 4 3 2
//
class Solution_32 {
 public:
  int longestValidParentheses(std::string s) {
    // ans
    // 记录最长合法长度，depth记录括号层次深度，start记录当前合法位置的第一个括号位置
    int ans = 0, depth = 0, start = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        ++depth;
      } else {
        --depth;
        if (depth < 0) {
          start = i;
          depth = 0;
        } else if (depth == 0) {
          ans = std::max(ans, i - start);
        }
      }
    }
    //上面如果遇到左括号多 例如((()(),不能到depth=0的时候
    //所以再反向扫描一遍
    depth = 0;
    start = s.size();
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == ')') {
        ++depth;
      } else {
        --depth;
        if (depth < 0) {
          start = i;
          depth = 0;
        } else if (depth == 0) {
          ans = std::max(ans, start - i);
        }
      }
    }
    return ans;
  }
};
class Solution_32_bak {
 public:
  int longestValidParentheses(std::string s) {
    std::stack<int> stk;  //栈，记录（的位置
    int len = 0;
    int start = 0;  //最长合法子串的起始位置
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        //（的位置入栈
        stk.push(i);
      } else {
        //当遇到），且栈为空时，将合法位置移到后一位
        if (stk.empty()) start = i + 1;
        //当遇到），栈不为空
        else {
          //将栈顶元素出栈
          stk.pop();
          //如果此时栈为空，更新最大合法长度为len,i-start+1中的较大值
          //如果栈不为空，更新最大合法长度为len,i-stk.top()中的较大值
          len = stk.empty() ? std::max(len, i - start + 1)
                            : std::max(len, i - stk.top());

          //)))()()()(((((())
        }
      }
    }
    return len;
  }
};
#endif