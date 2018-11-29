#ifndef SOLUTION_5
#define SOLUTION_5
/*
Given a string s,
find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.

找字符串中最长的回文序列
如果不止一个返回其中一个即可

我朴素的想法是
遍历一遍，找和当前字符一致的下一个字符
判断这两个字符之间是不是回文
同时记录最长的回文长度，减少遍历的次数
记录最长的回文起始位置
就是判断的次数太多了

更快的办法
从中间向两边扩展，判断两边元素是否一样

 */
#include <string>
class Solution_5 {
 public:
  std::string longestPalindrome(std::string s) {
    int max = 0;
    std::string res;
    for (int i = 0; i < s.size() - max; i++) {
      for (int j = i + 1 + max; j < s.size(); j++) {
        if (s[j] == s[i]) {
          if (isPalindrome(s, i, j)) {
            res = s.substr(i, j - i + 1);
            max = j - i;
          }
        }
      }
      if (res.empty()) res = s[0];
    }
    return res;
  }

 private:
  bool isPalindrome(std::string s, int start, int end) {
    while (start < end) {
      if (s[start] == s[end]) {
        start++;
        end--;
      } else {
        return false;
      }
    }
    return true;
  }
};
class Solution_5_bak {
 public:
  std::string longestPalindrome(std::string s) {
    //边界条件判断
    if (s.size() == 0) return "";
    if (s.size() == 1) return s;

    int length = 1;  //默认最长的回文长度为1
    int start = 0;   //起始位置为0

    for (int i = 0; i < s.size();) {
      //如果剩余字符串长度比当前找到的最长回文的一半小，跳出循环
      if (s.size() - i <= length / 2) break;

      int j = i;
      int k = i;
      //如果s[k]==s[k+1]，则从i位置一直走到字符串尾部
      //找到第一个和i位置字符不一样字符的位置
      //从i...k的所有字符是一样的
      //因为要找一个'中间'，中间本身要是一个回文，那么像bb这种字符串也要当成中间
      //这个循环就完成了这个目的，非常巧妙
      while (k < s.size() - 1 && s[k + 1] == s[k]) k++;

      i = k + 1;
      //从i...k位置向两边扩展，判断两端是否满足回文序列条件
      while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) {
        k++;
        j--;
      }
      //记录长度和位置
      int new_length = k - j + 1;
      if (new_length > length) {
        length = new_length;
        start = j;
      }
    }

    return s.substr(start, length);
  }
};
#endif