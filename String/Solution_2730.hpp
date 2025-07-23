#ifndef SOLUTION_2730
#define SOLUTION_2730
/*
You are given a digit string s that consists of digits from 0 to 9.

A string is called semi-repetitive if there is at most one adjacent pair of the
same digit.

For example, "0010", "002020", "0123", "2002", and "54944" are semi-repetitive

while the following are not:
"00101022" (adjacent same digit pairs are 00 and 22),
and "1101234883" (adjacent same digit pairs are 11 and 88).

Return the length of the longest semi-repetitive of s.


给出一个只有数字的字符串。

定义：如果一个字符串中，至多只有一对相邻数字相同，那么称字符串为“半重复”。

给出这个字符串中最长的“半重复”字符串的长度。

注意数组最短为 1
---
滑动窗口做法
一个变量记录是否出现过相邻重复元素，
一个变量记录组重复元素右边元素的下标。

开始滑动窗口
判断新进入窗口元素是否和前一个元素相同。
如果相同
    如果之前已经有相同元素了，
    那么就要收缩滑动窗口到上一对重复元素的右边元素的下标。

    如果之前没有相同元素，记录重复出现和当前元素下标（即重复元素对右侧下标）

更新最长“半重复”字符串长度，窗口继续向右扩展


*/
#include <algorithm>
#include <string>
class Solution_2730 {
 public:
  int longestSemiRepetitiveSubstring(std::string s) {
    int left = 0, right = 1;
    int size = s.size();
    int max = 1;  // 数组最短为 1，结果至少是 1
    bool exist = false;
    int last = s[0];      // 数组最短为 1，循环从第 2 个开始
    int semi_index = -1;  // 上一个重复元素对的右边元素下标
    while (right < size) {
      int num = s[right];
      if (num == last) {
        if (exist) {
          left = semi_index;  // 更新左指针到前面一对重复元素的右边下标
        }
        exist = true;
        semi_index = right;
      }
      last = num;
      max = std::max(max, right - left + 1);
      right++;
    }
    return max;
  }
};
/*
参考 0x3f 的做法
如果题目给出的是：至多有 x 对相邻数字相同满足要求
这个版本代码可以适用。
记录出现对数，当对数大于 x 时，左指针向右收缩，
收缩到跳过最左侧的相邻对的右边元素。
*/
class Solution_2730_1 {
 public:
  int longestSemiRepetitiveSubstring(std::string s) {
    int left = 0, right = 1;
    int times = 1;  // 相邻数字相同对数，题中为1。可适应可变情况。
    int size = s.size();
    int max = 1;
    int exist = 0;
    int last = s[0];
    while (right < size) {
      int num = s[right];
      if (num == last) {
        exist++;
      }
      if (exist > times) {
        while (s[left] != s[left + 1]) {
          left++;
        }
        left++;
        exist--;
      }
      last = num;
      max = std::max(max, right - left + 1);
      right++;
    }
    return max;
  }
};
#endif