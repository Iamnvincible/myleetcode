/*
 * @Author: Jie Lin
 * @Date: 2021-05-16 16:09:42
 * @LastEditTime: 2021-05-16 16:55:30
 * @LastEditors: Jie Lin
 * @Description:Scramble String
 * @FilePath: \myleetcode\DP\Solution_87.hpp
 *
 */
#ifndef SOLUTION_87
#define SOLUTION_87
#include <string>
#include <vector>
class Solution_87 {
 public:
  bool isScramble(std::string s1, std::string s2) {
    if (s1 == s2) return true;
    int size = s1.size();
    std::vector<std::vector<std::vector<bool>>> dp(
        size,
        std::vector<std::vector<bool>>(size, std::vector<bool>(size + 1)));
    // len 表示字符串的长度
    for (size_t len = 1; len <= size; len++) {
      for (size_t i = 0; i <= size - len; i++) {
        for (size_t j = 0; j <= size - len; j++) {
          if (len == 1) {
            //如果字符串长度为1，直接比较即可
            dp[i][j][1] = s1[i] == s2[j];
          } else {
            for (size_t k = 0; k < len; k++) {
              if ((dp[i][j][k] && dp[i + k][j + k][len - k]) ||
                  (dp[i + k][j][len - k] && dp[i][j + len - k][k])) {
                dp[i][j][len] = true;
                break;
              }
            }
          }
        }
      }
    }
    return dp[0][0][size];
  }
};
#endif