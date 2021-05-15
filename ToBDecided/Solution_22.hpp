/*
 * @Author: Jie Lin
 * @Date: 2021-05-06 22:36:46
 * @LastEditTime: 2021-05-07 00:05:47
 * @LastEditors: Jie Lin
 * @Description:Generate Parentheses
 * @FilePath: \myleetcode\ToBDecided\Solution_22.hpp
 *
 */
#ifndef SOLUTION_22
#define SOLUTION_22
#include <stack>
#include <string>
#include <vector>
/**
 * @brief
 * @note
 *
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * @retval None
 */
class Solution_22 {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    std::stack<char> s;
    generate(n, s, "", res);
    return res;
  }

 private:
  void generate(int n, std::stack<char> s, std::string str,
                std::vector<std::string> &res) {
    if (n == 0) {
      while (!s.empty()) {
        s.pop();
        str += ')';
      }
      res.push_back(str);
    } else {
      if (s.empty()) {
        s.push('(');
        str += '(';
        generate(n - 1, s, str, res);
      } else {
        s.push('(');
        str += '(';
        generate(n - 1, s, str, res);
        s.pop();
        s.pop();
        str.pop_back();
        str += ')';
        generate(n, s, str, res);
      }
    }
  }
};
#endif