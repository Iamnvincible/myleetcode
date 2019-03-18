#ifndef SOLUTION_58
#define SOLUTION_58
/*
Given a string s consists of upper/lower-case alphabets and empty space
characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters
only.
给出一个包含字母和空格的字符串，找出其中最后一个单词的长度
单词定义为中间没有空格

从后往前找一个单词
后面第一个不是空格的位置，再往前找一个空格
*/
#include <algorithm>
#include <string>
class Solution_58 {
 public:
  int lengthOfLastWord(std::string s) {
    int res = 0;
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') {
      i--;
    }
    while (i >= 0 && s[i] != ' ') {
      res++;
      i--;
    }
    return res;
  }
};
/*
使用标准库
从右找第一个是字母的位置
再从这个位置往左找第一个不是字母的位置
用distance求两个迭代器之间的距离返回
*/
class Solution_58_bak {
 public:
  int lengthOfLastWord(std::string s) {
    auto first = std::find_if(s.rbegin(), s.rend(), ::isalpha);
    auto last = std::find_if_not(first, s.rend(), ::isalpha);
    return std::distance(first, last);
  }
};
#endif