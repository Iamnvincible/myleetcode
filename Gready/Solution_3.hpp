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
#include <unordered_map>
/**
 * @brief 给出一个字符串，返回其中最长没有重复字符的子字符串的长度
 * @note
 * @retval None
3. Longest Substring Without Repeating Characters

 */
class Solution_3 {
 public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.empty()) return 0;
    int longest = 0;
    int start = 0;  // 记录子字符串的开始位置
    int i = 1;
    while (i < s.size()) {
      auto beg = s.begin() + start;            // 子字符串的开始位置迭代器
      auto end = s.begin() + i;                // 子字符串的结束位置迭代器
      auto found = std::find(beg, end, s[i]);  // 在子字符串中查找当前遇到的字符
      // 如果当前遇到的字符在子字符串中出现
      // 那么就要更新子字符串开始的位置
      // 先更新最长无重复子字符串长度
      // 新的子字符串开始位置为当前字符出现位置+1
      if (found != end) {
        longest = std::max(i - start, longest);
        start = found - s.begin() + 1;
      }
      i++;
    }
    // 最后还要比较最后一个子字符串的长度和之前最长子字符串的长度
    return std::max(i - start, longest);
  }
};
// 参考 209 713 适用滑动窗口
// 用哈希表记录字符出现的次数
// 在扩展滑动窗口时，如果新加入的字符数量超过 1，
// 说明在左边存在相同字符，将相同字符从窗口中移除；
// 如果没有出现重复字符，可以更新最长子字符串长度。
class Solution_3_2 {
 public:
  int lengthOfLongestSubstring(std::string s) {
    int result = 0;
    std::unordered_map<char, int> record;
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      record[s[right]]++;
      while (record[s[right]] > 1) {
        record[s[left++]]--;
      }
      result = std::max(result, right - left + 1);
    }
    return result;
  }
};
#endif