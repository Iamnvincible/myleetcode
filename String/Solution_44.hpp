#ifndef SOLUTION_44
#define SOLUTION_44
/*
Given an input string (s) and a pattern (p),
implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ?
or *.

实现通配符的匹配，类似于10题正则匹配

一种方法还是用递归，但是复杂度甚至达到了惊人的n!*m!,模式串里的*一多就超时

还是用动态规划解题

还有让两个下标走到头，看p的下标是否走完
 */
#include <string>
#include <vector>
class Solution_44 {
 public:
  bool isMatch(std::string s, std::string p) {
    if (p.empty()) return s.empty();
    if (p[0] != '*') {
      return !s.empty() && (p[0] == '?' || p[0] == s[0]) &&
             isMatch(s.substr(1), p.substr(1));
    } else {
      //连续的*会造成递归过于复杂，只留下一个*，但还是没有解决根本问题
      while (p.size() > 1 && p[1] == '*') {
        p = p.substr(1);
      }
      if (s.empty()) {
        return isMatch(s, p.substr(1));
      }
      return !s.empty() && (isMatch(s, p.substr(1)) || isMatch(s.substr(1), p));
    }
  }
};
class Solution_44_bak {
 public:
  bool isMatch(std::string s, std::string p) {
    int row = p.size();
    int col = s.size();
    std::vector<std::vector<bool>> dp(row + 1,
                                      std::vector<bool>(col + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= col; i++) {
      dp[0][i] = false;
    }
    for (int j = 1; j <= row; j++) {
      if (p[j - 1] == '*') {
        dp[j][0] = dp[j - 1][0];
      } else {
        dp[j][0] = false;
      }
    }
    for (int i = 1; i <= col; i++) {
      for (int j = 1; j <= row; j++) {
        if (p[j - 1] == '*') {
          dp[j][i] = dp[j - 1][i] || dp[j][i - 1];
        } else {
          dp[j][i] =
              (p[j - 1] == '?' || p[j - 1] == s[i - 1]) && dp[j - 1][i - 1];
        }
      }
    }
    return dp[row][col];
  }
};
class Solution_44_bak_1 {
 public:
  bool isMatch(std::string s, std::string p) {
    int n = s.length(), m = p.length();
    int i = 0, j = 0, ir = 0, star = -1;
    while (i < n) {
      if (j < m && (p[j] == '?' || p[j] == s[i])) {
        //能够匹配到？或相同字符，i,j都往后
        i++;
        j++;
      } else if (j < m && p[j] == '*') {
        //碰到*，j往后走，直到p[j]不是*
        star = j;  //记录*的位置
        j++;       // j往后走
        ir = i;    // ir记录第一次碰到*时的i

      }
      //当字符不匹配且遇到的p[j]不是*时
      //如果出现*后又不匹配，i会一直走到头退出，而j!=m
      else if (star != -1) {
        // j记录为*后面的非*字符
        // i,ir记录为第一次碰到*的后一个字符位置
        j = star + 1;  //记录连续*后的第一个字符
        i = ++ir;  // i,ir指向第一次碰到*字符的后一个，因为有*，可以把这次不匹配给抵消
      } else
        return false;
    }
    //处理p末尾存在的*
    while (j < m && p[j] == '*') j++;
    return j == m;
  }
};
#endif