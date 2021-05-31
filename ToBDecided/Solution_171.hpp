/*
 * @Author: Jie Lin
 * @Date: 2021-05-31 22:19:29
 * @LastEditTime: 2021-05-31 22:20:37
 * @LastEditors: Jie Lin
 * @Description:Excel Sheet Column Number
 * @FilePath: \myleetcode\ToBDecided\Solution_171.hpp
 *
 */
#ifndef SOLUTION_171
#define SOLUTION_171
#include <cmath>
#include <string>
class Solution_171 {
 public:
  int titleToNumber(std::string columnTitle) {
    int res = 0;
    for (int i = 0; i < columnTitle.size(); i++) {
      res +=
          (columnTitle[i] - 'A' + 1) * std::pow(26, columnTitle.size() - 1 - i);
    }
    return res;
  }
};
#endif