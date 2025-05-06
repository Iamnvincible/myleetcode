/*
 * @Author: Jie Lin
 * @Date: 2021-05-26 23:25:22
 * @LastEditTime: 2021-05-29 20:21:50
 * @LastEditors: Jie Lin
 * @Description:Excel Sheet Column Title
 * @FilePath: \myleetcode\ToBDecided\Solution_168.hpp
 *
 */
#ifndef SOLUTION_168
#define SOLUTION_168
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
/**
 * @brief  将数字转化为excel的列字母表示法
 * 像是26进制，却又不是
 * @note
 * 第一种方法更有普适性，可以添加更多字符作为列符号
 * @retval None
 */
class Solution_168 {
 public:
  std::string convertToTitle(int columnNumber) {
    const std::string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int base = table.size();
    std::vector<int> accumulate = calcAccmulates(base);
    std::string res;
    int ex = 0;  //最高次
    while (ex < accumulate.size() && columnNumber >= accumulate[ex]) {
      ex++;
    }
    ex--;
    while (ex >= 0) {
      int count = 0;
      while (count < base && columnNumber >= accumulate[ex]) {
        columnNumber -= std::pow(base, ex);
        count++;
      }
      res.push_back(table[count - 1]);
      ex--;
    }
    return res;
  }

 private:
  std::vector<int> calcAccmulates(const int base) {
    std::vector<int> res;
    int item = 0;
    int exp = 0;
    while (item + std::pow(base, exp) <= INT_MAX) {
      item += std::pow(base, exp);
      res.push_back(item);
      exp++;
    }
    return res;
  }
  class Solution_168_2 {
   public:
    std::string convertToTitle(int columnNumber) {
      std::string res = "";
      int n = columnNumber;
      while (n) {
        if (n % 26 == 0) {
          res += 'Z';
          n -= 26;
        } else {
          res += n % 26 - 1 + 'A';
          n -= n % 26;
        }
        n /= 26;
      }
      std::reverse(res.begin(), res.end());
      return res;
    }
  };
};
#endif