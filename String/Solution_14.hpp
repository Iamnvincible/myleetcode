#ifndef SOLUTION_14
#define SOLUTION_14
/*
Write a function to find the longest common prefix string
amongst an array of strings.

If there is no common prefix, return an empty string "".

求一系列字符串的最长公共前缀
从第一个字符串的0位置开始挨个比较，直到出现不一致
空字符串的.substr(0,0)是什么？
 */
#include <string>
#include <vector>
class Solution_14 {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) {
      return "";
    } else {
      int j = 0;
      while (j < strs[0].size()) {
        auto ch = strs[0][j];
        for (int i = 1; i < strs.size(); i++) {
          if (strs[i][j] != ch) {
            return strs[0].substr(0, j);
          }
        }
        j++;
      }
      return strs[0];
    }
  }
};
#endif
