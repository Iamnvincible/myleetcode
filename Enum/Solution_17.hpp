/*
 * @Author: Jie Lin
 * @Date: 2021-04-20 22:12:14
 * @LastEditTime: 2021-04-20 23:05:12
 * @LastEditors: Jie Lin
 * @Description:Letter Combinations of a Phone Number
 * @FilePath: \myleetcode\Enum\Solution_17.hpp
 *
 */
#ifndef SOLUTION_17
#define SOLUTION_17
/**
 * @brief
 * 电话上2-9上分别对应几个字母，给出按键序列，返回所有字母的组合
 * 递归
 * @note
 * @retval None
 */
#include <string>
#include <unordered_map>
#include <vector>
class Solution_17 {
 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> res;
    std::vector<std::string> keys = {"abc", "def",  "ghi", "jkl",
                                     "mno", "pqrs", "tuv", "wxyz"};
    std::unordered_map<int, std::string> table;
    for (size_t i = '2'; i <= '9'; i++) {
      table[i] = keys[i - '2'];
    }
    get_combination(digits, "", table, res);
    return res;
  }

 private:
  void get_combination(std::string digits, std::string part,
                       std::unordered_map<int, std::string>& table,
                       std::vector<std::string>& res) {
    if (digits.empty()) {
      if (part.size()) res.push_back(part);
      return;
    }
    std::string digit_string = table[digits[0]];
    for (size_t j = 0; j < digit_string.size(); j++) {
      part.push_back(digit_string[j]);
      if (digits.size() > 1) {
        get_combination(digits.substr(1), part, table, res);
      } else {
        res.push_back(part);
      }
      part.pop_back();
    }
  }
};
#endif