#ifndef SOLUTION_65
#define SOLUTION_65
/* Validate if a given string can be interpreted as a decimal number.
Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
验证给定的字符串能否转换成一个科学计数法的数字

法一，if一路判断
法二，使用库函数strtod
*/
#include <string>
class Solution_65 {
 public:
  bool isNumber(std::string s) {
    //判断字符串为空时
    if (s.size() < 1) {
      return false;
    } else {
      int i = 0;
      // skip blank跳过字符串左边的空格
      while (s[i] == ' ') {
        i++;
      }
      //当字符串中只有空格，i=s.size()
      if (i == s.size()) {
        return false;
      }
      //跳过字符串右边的空格
      int k = s.size() - 1;
      while (s[k] == ' ') {
        k--;
      }
      //是否记录过e
      bool exp = false;
      //是否记录过小数点
      bool decimal = false;
      // e后面是否记录过符号
      bool expsign = false;
      for (int j = i; j <= k; j++) {
        //对去掉过空格的部分
        // illegal char首先判断字符是否合法
        if (!islegal(s[j])) {
          return false;
        }
        //在第一个有效字符的前提下
        else {
          switch (s[j]) {
            case '+':
              //符号+，-只能出现在第一个或e后面的第一个，否则返回false
              if (j != i && !exp)
                return false;
              else if (j != i && exp && !expsign) {
                expsign = true;
                break;
              } else if (j == i) {
                break;
              } else {
                return false;
              }
            case '-':
              if (j != i && !exp)
                return false;
              else if (j != i && exp && !expsign) {
                expsign = true;
                break;
              } else if (j == i) {
                break;
              } else {
                return false;
              }
            case 'e':
              // e只能出现在数字的后面，至多出现一次
              if (j == i)
                return false;
              else if (exp)
                return false;
              else {
                bool isnum = false;
                for (int m = i; m < j; m++) {
                  if (s[m] >= '0' && s[m] <= '9') {
                    isnum = true;
                    break;
                  }
                }
                if (isnum) {
                  exp = true;
                  break;
                } else {
                  return false;
                }
              }

            case '.':
              //小数点只能出现一次
              if (decimal)
                return false;
              else if (exp) {
                return false;
              } else {
                decimal = true;
                break;
              }
            default:
              continue;
          }
        }
      }
      //去掉只有.的情况  1.或.1为合法
      if (s[k] == '.' && s[i] == '.') {
        return false;
      }
      //去掉最后一个字符是 e + -
      else if (s[k] == 'e' || s[k] == '+' || s[k] == '-') {
        return false;
      }
      //必须出现数字
      else {
        for (int m = i; m <= k; m++) {
          if (s[m] >= '0' && s[m] <= '9') {
            return true;
          }
        }
        return false;
      }
    }
  }
  //所有合法字符
  bool islegal(char c) {
    char legal[] = {'0', '1', '2', '3', '4', '5', '6',
                    '7', '8', '9', 'e', '+', '-', '.'};
    for (int i = 0; i < 14; i++) {
      if (c == legal[i]) {
        return true;
      }
    }
    return false;
  }
};

class Solution_65_bak {
 public:
  bool isNumber(std::string s) {
    // strtod需要一个const 修饰的字符串
    const char* st = s.c_str();
    //一个转换数字后剩下的字符串 指向最后被转译字符的后一字符
    char* endptr;
    //返回数字，这里不用接收
    strtod(st, &endptr);
    if (endptr == st) return false;
    for (; *endptr; ++endptr)//判断后面的字符是不是只有空格
      if (!isspace(*endptr)) return false;
    return true;
  }
};
#endif