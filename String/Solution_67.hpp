#ifndef SOLUTION_67
#define SOLUTION_67
/* Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.
把两个代表二进制数字的字符串相加
返回一个二进制字符串结果
一种方法把两个字符串对齐后再加
一种方法在相加的过程中判断长度是不是够
注意最前面一位要进位
*/
#include <string>
class Solution_67 {
 public:
  std::string addBinary(std::string a, std::string b) {
    int size_a = a.size();
    int size_b = b.size();
    std::string res;
    int add = 0;
    if (size_a > size_b) {
      b.insert(0, size_a - size_b, '0');
    } else {
      a.insert(0, size_b - size_a, '0');
    }
    int max = size_a > size_b ? size_a : size_b;
    for (int j = max - 1; j >= 0; j--) {
      int ai = a[j] - '0';
      int bi = b[j] - '0';
      char s = (ai + bi + add) % 2 + '0';
      add = (ai + bi + add) / 2;
      res.insert(0, 1, s);
    }
    if (add) res.insert(0, 1, '1');
    return res;
  }
};
class Solution_67_bak {
 public:
  std::string addBinary(std::string a, std::string b) {
    int size_a = a.size();
    int size_b = b.size();
    std::string res;
    int add = 0;
    int max = size_a > size_b ? size_a : size_b;
    for (int j = max - 1; j >= 0; j--) {
      int ai = size_a > 0 ? a[--size_a] - '0' : 0;
      int bi = size_b > 0 ? b[--size_b] - '0' : 0;
      char s = (ai + bi + add) % 2 + '0';
      add = (ai + bi + add) / 2;
      res.insert(0, 1, s);
    }
    if (add) res.insert(0, 1, '1');
    return res;
  }
};
#endif