/*
 * @Author: Jie Lin
 * @Date: 2021-04-28 22:07:32
 * @LastEditTime: 2021-04-28 23:18:30
 * @LastEditors: Jie Lin
 * @Description:Longest Substring Without Repeating Characters
 * @FilePath: \myleetcode\Gready\Solution_3.hpp
 *
 */
#ifndef SOLUTION_3
#define SOLUTION_3
#include <algorithm>
#include <string>
/**
 * @brief 给出一个字符串，返回其中最长没有重复字符的子字符串的长度
 * @note
 * @retval None
 */
class Solution_3 {
 public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.empty()) return 0;
    int longest = 0;
    int start = 0;  //记录子字符串的开始位置
    int i = 1;
    while (i < s.size()) {
      auto beg = s.begin() + start;  //子字符串的开始位置迭代器
      auto end = s.begin() + i;      //子字符串的结束位置迭代器
      auto found = std::find(beg, end, s[i]);  //在子字符串中查找当前遇到的字符
      //如果当前遇到的字符在子字符串中出现
      //那么就要更新子字符串开始的位置
      //先更新最长无重复子字符串长度
      //新的子字符串开始位置为当前字符出现位置+1
      if (found != end) {
        longest = std::max(i - start, longest);
        start = found - s.begin() + 1;
      }
      i++;
    }
    //最后还要比较最后一个子字符串的长度和之前最长子字符串的长度
    return std::max(i - start, longest);
  }
};
#endif