/*
 * @Author: Jie Lin
 * @Date: 2021-05-10 22:40:34
 * @LastEditTime: 2021-05-11 23:32:59
 * @LastEditors: Jie Lin
 * @Description:Interleaving String
 * @FilePath: \myleetcode\DP\Solution_97.hpp
 *
 */
#ifndef SOLUTION_97
#define SOLUTION_97
#include <string>
//普通递归超时
class Solution_97 {
 public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    if (s1.empty() && s2.empty() && s3.empty()) {
      return true;
    }

    int s1prefix = longestprefix(s1, s3);
    bool s1try = false;
    while (s1prefix >= 0) {
      s1try =
          isInterleave(s1.substr(s1prefix + 1), s2, s3.substr(s1prefix + 1));
      if (s1try) {
        return s1try;
      } else {
        s1prefix--;
      }
    }
    int s2prefix = longestprefix(s2, s3);
    if (!s1try && s2prefix != -1) {
      while (s2prefix >= 0) {
        bool s2try =
            isInterleave(s1, s2.substr(s2prefix + 1), s3.substr(s2prefix + 1));
        if (s2try) {
          return s2try;
        } else {
          s2prefix--;
        }
      }
    }
    return false;
  }

 private:
  int longestprefix(std::string s1, std::string s2) {
    int res = 0;
    while (res < s1.size() && res < s2.size()) {
      if (s1[res] != s2[res]) {
        return res - 1;
      }
      res++;
    }
    return res - 1;
  }
};
/**
 * @brief  动态规划
 * @note   s1长度i,s2长度j
 *         目标s3，长度i+j
 * 动态规划数组f[i+1][j+1]表示长度i，j数组匹配s3的结果
 * @retval None
 */
class Solution_97_2 {
 public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    std::vector<std::vector<bool>> f(s1.size() + 1,
                                     std::vector<bool>(s2.size() + 1));
    // f[0][0]表示s1,s2都是空字符串时的匹配结果，两者都为空,两者长度与s3相同，那么必然能组成s3
    f[0][0] = true;
    //初始化第一列,假设s2为空,只有s1来组成s3
    //首先s1[i]的上一个位置f[i-1][0]必须为真才能继续后面的匹配
    //在f[i-1][0]为真的条件下,s1[i]必须和s3[i]相同,f[i][0]才为真
    //这里i的起始位置为1,需要往前推一位
    //注意f的长度,i<=s1.size()
    for (size_t i = 1; i <= s1.size(); i++) {
      f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
    }
    //初始化第一行
    for (size_t i = 1; i <= s2.size(); i++) {
      f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
    }
    for (size_t i = 1; i <= s1.size(); i++) {
      for (size_t j = 1; j <= s2.size(); j++) {
        f[i][j] = (f[i][j - 1] && s2[j - 1] == s3[i + j - 1]) ||
                  (f[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
      }
    }
    return f.back().back();
  }
};
#endif