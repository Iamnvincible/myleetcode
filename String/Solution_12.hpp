#ifndef SOLUTION_12
#define SOLUTION_12
/*Roman numerals are represented by seven different symbols:
I, V, X, L, C, D and M.
将不超过3999的数字转换成相应的罗马数字
注意罗马数字的表示方法
例如：
4=IV而不是IIII
naive 的办法是从大到小逐个判断

senior的方法用数组代表特殊的边界
用计算的值替代诸多的判断，非常优雅
*/
#include <string>
class Solution_12 {
 public:
  std::string intToRoman(int num) {
    // M D C L X V I
    std::string res = "";
    if (num >= 1000) {
      auto ext = num / 1000;
      res.insert(0, ext, 'M');
      num = num - ext * 1000;
    }
    if (num >= 900) {
      res.push_back('C');
      res.push_back('M');
      num = num - 900;
    }
    if (num >= 500) {
      auto ext = num - 500;
      res.push_back('D');
      while (ext >= 100) {
        res.push_back('C');
        ext -= 100;
      }
      num = ext;
    }
    if (num >= 400) {
      res.push_back('C');
      res.push_back('D');
      num -= 400;
    }
    if (num >= 100) {
      auto ext = num / 100;
      while (ext > 0) {
        res.push_back('C');
        ext--;
      }
      num = num % 100;
    }
    if (num >= 90) {
      res.push_back('X');
      res.push_back('C');
      num -= 90;
    }
    if (num >= 50) {
      auto ext = num - 50;
      res.push_back('L');
      while (ext >= 10) {
        res.push_back('X');
        ext -= 10;
      }
      num = ext;
    }
    if (num >= 40) {
      res.push_back('X');
      res.push_back('L');
      num -= 40;
    }
    if (num >= 10) {
      auto ext = num / 10;
      while (ext > 0) {
        res.push_back('X');
        ext--;
      }
      num %= 10;
    }
    if (num >= 9) {
      res.push_back('I');
      res.push_back('X');
      num -= 9;
    }
    if (num >= 5) {
      auto ext = num - 5;
      res.push_back('V');
      while (ext > 0) {
        res.push_back('I');
        ext--;
      }
      num = 0;
    }
    if (num >= 4) {
      res.push_back('I');
      res.push_back('V');
      num -= 4;
    }
    while (num > 0) {
      res.push_back('I');
      num--;
    }
    return res;
  }
};
class Solution_12_bak {
 public:
  std::string intToRoman(int num) {
    //所有特殊数字边界
    const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const std::string symbol[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                  "XL", "X",  "IX", "V",  "IV", "I"};
    std::string roman;
    for (size_t i = 0; num > 0; ++i) {
      //给定数字中有几个边界则在字符串中加入对应罗马数字
      int count = num / radix[i];
      num %= radix[i];
      for (; count > 0; --count) roman += symbol[i];
    }
    return roman;
  }
};
#endif