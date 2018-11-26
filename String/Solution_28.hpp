#ifndef SOLUTION_28
#define SOLUTION_28
/* Implement strStr().

Return the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.
求字符串在另一个字符串出现的位置
最简单的是暴力寻找
经典的有KMP算法
还有一个Boyer-Moore算法，我只能实现一半...但也能用
只有有空的时候再学习了...
*/
#include <string>
#include <unordered_map>
class Solution_28 {
 public:
  int strStr(std::string haystack, std::string needle) {
    if (needle.empty()) return 0;
    for (int i = 0; i < haystack.size(); i++) {
      int k = i;
      for (int j = 0; j < needle.size(); j++) {
        if (haystack[k] == needle[j]) {
          k++;
          if (k < haystack.size()) continue;
          break;
        }
        break;
      }
      if ((k - i) == needle.size()) {
        return i;
      }
    }
    return -1;
  }
};
class Solution_28_bak {
 public:
  int strStr(std::string haystack, std::string needle) {
    if (needle.empty()) return 0;
    int length = needle.size();
    if (length > haystack.size()) return -1;
    int i = length - 1;
    while (i < haystack.size()) {
      int k = i;
      int s = length - 1;
      while (haystack[k] == needle[s]) {
        k--;
        s--;
      }
      if (s < 0)
        return i - length + 1;
      else {
        i += s - lastoccur(needle, haystack[k], s);
      }
    }
    return -1;
  }

 private:
  int lastoccur(std::string needle, char c, int last) {
    for (int i = last - 1; i >= 0; i--) {
      if (needle[i] == c) {
        return i;
      }
    }
    return -1;
  }
  /*
  int suffix(std::string needle) {
    std::unordered_map<int, int> table;
    table[0] = 0;
    int length = needle.size();
    for (int i = 1; i < length; i++) {
      if (length - i > i) {
      } else {
        table[i] = length;
      }
      int pos = -1;
      for (int j = i; j < length; j++) {
        int temp = lastoccur(needle, needle[j], i) != -1);
        if (temp != pos + 1) break;
      }
    }
  }
  */
};
#endif