/*
 * @Author: Jie Lin
 * @Date: 2021-05-03 14:21:19
 * @LastEditTime: 2021-05-04 22:44:05
 * @LastEditors: Jie Lin
 * @Description:Palindrome Partitioning II
 * @FilePath: \myleetcode\DP\Solution_132.hpp
 *
 */

#ifndef SOLUTION_132
#define SOLUTION_132
#include <algorithm>
#include <string>
#include <vector>
/**
 * @brief
 * 给出一个字符串，求将这个字符串分隔为所有子字符串都是回文字符串的分隔位置数量（次数）
 * 动态规划，先完成647题
 * @note
 * @retval None
 */
class Solution_132 {
 public:
  int minCut(std::string s) {
    if (s.empty()) return 0;
    auto size = s.size();
    std::vector<std::vector<bool>> matrix(size, std::vector<bool>(size));
    std::vector<int> dp(size);  // dp[i]记录0-i范围内的子字符串最少分隔次数
    //循环从左到右开始，一次计算d[i]的值
    for (size_t i = 0; i < size; i++) {
      dp[i] = i;  // 0-i范围内字符串最大分隔次数为i次
      //在子字符串 0~i内寻找回文字符串，以减少dp[i]的值
      //为了寻找回文字符串，需要穷举0~i内所有子字符串，并判断是否为回文字符串
      //这里并非穷举范围内所有子字符串，只穷举j-i范围内的子字符串，其他子字符串已经由之前大循环完成
      for (size_t j = 0; j <= i; j++) {
        //判断j~i内子字符串是否是回文字符串
        if (i - j >= 2) {
          matrix[j][i] = s[i] == s[j] && matrix[j + 1][i - 1];
        } else {
          matrix[j][i] = s[i] == s[j];
        }
        //如果j~i范围的子字符串是一个回文字符串
        // dp[i]就是 dp[j-1]+1 和 dp[i]之间的较小值
        // dp[i]在之前已经赋过初值，如果j~i之间是一个回文字符串，那么dp[i]的值即可减少为dp[j-1]+1
        if (matrix[j][i]) {
          //如果j=0,即0-i范围内的字符串是一个回文字符串，不需要分隔,dp[i]=0
          if (j == 0) {
            dp[i] = 0;
          } else {
            dp[i] = std::min(dp[i], dp[j - 1] + 1);
          }
        }
        //如果j~i范围内不是一个回文字符串，dp[i]也会从i减少到
        // dp[j-1]+i-j
      }
    }
    return dp[size - 1];
  }
};

#endif