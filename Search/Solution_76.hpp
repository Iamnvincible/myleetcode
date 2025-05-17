#ifndef SOLUTION_76
#define SOLUTION_76
#include <string>
#include <unordered_map>
/*
76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively,
return the minimum window of s such
    that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
给出字符串 s 和 t。在 s 中找出一个最短的子字符串，使其满足：
每个 t 中的字符串都在子字符串中出现，
t 中的字符可能会重复，子字符串中最要要重复相应次数。
可以多出现，但不能少。
如果不存在，返回空字符串。

方法一：
适用滑动指针
哈希表记录 t 中每个字符出现的次数。
向右扩大窗口时，如果字符在 t 中出现，将其次数 -1。
当每个字符都出现过 t 中出现的次数时，更新最短字符串。
此时的窗口是满足要求 t 的子字符串，但左边可能可以缩短。
因此从左边收缩窗口长度，收缩时如果遇到 t 中字符，需要将其计数 +1。
但由于字符出现次数可以超过 t 中出现的次数，计数可能时负数。
窗口可以继续收缩，直到有字符的计数≥1，也就是不符合 t 要求的位置。
继续向右扩展，重复上述步骤。

但由于哈希表的查找时间复杂度与长度相关，即 t 中字符集数量。
外层复杂度为 n，内层为 m，总体为 n^2。
在字符串长度很长时会超时。
*/
class Solution_76 {
 public:
  std::string minWindow(std::string s, std::string t) {
    std::string result = "";
    int minlen = s.size();
    int minleft = -1;
    std::unordered_map<char, int> record;
    for (auto s : t) {
      record[s]++;
    }
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      if (record.contains(s[right])) {
        record[s[right]]--;
        while (alloccured(record)) {
          if (minlen >= right - left + 1) {
            minleft = left;
            minlen = right - left + 1;
          }
          if (record.contains(s[left])) {
            record[s[left]]++;
          }
          left++;
        }
      }
    }
    if (minleft >= 0) {
      result = s.substr(minleft, minlen);
    }
    return result;
  }

 private:
  bool alloccured(std::unordered_map<char, int> mag) {
    for (auto iter = mag.begin(); iter != mag.end(); ++iter) {
      if (iter->second > 0) {
        return false;
      }
    }
    return true;
  }
};
/*
为了解决哈希表查找效率问题，继续分析目标。
查找时，只要直到是不是每个字符都已经出现过。
已经出现过的字符对应哈希表的值至多为 0，可以为负数。
可以用一个变量记录字符尚未归零（或负数）的个数。
当这个计数归零时，说明所有字符都出现过了，可以更新最短子字符串。
收缩左边时，需要增加 t 中出现字符的计数，
当其增大到 1 时，说明不能再收缩，需要向右扩展。
同时计数变量 +1.
*/
class Solution_76_2 {
 public:
  std::string minWindow(std::string s, std::string t) {
    std::string result = "";
    int minlen = s.size();
    int minleft = -1;
    std::unordered_map<char, int> record;
    for (auto s : t) {
      record[s]++;
    }
    int unique = record.size();
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      if (record.contains(s[right])) {
        record[s[right]]--;
        if (record[s[right]] == 0) unique--;
        while (unique == 0) {
          if (minlen >= right - left + 1) {
            minleft = left;
            minlen = right - left + 1;
          }
          if (record.contains(s[left])) {
            record[s[left]]++;
            if (record[s[left]] == 1) unique++;
          }
          left++;
        }
      }
    }
    if (minleft >= 0) {
      result = s.substr(minleft, minlen);
    }
    return result;
  }
};
#endif