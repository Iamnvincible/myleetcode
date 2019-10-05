#ifndef SOLUTION_166
#define SOLUTION_166
/*
Given two integers representing the numerator and denominator of a fraction,
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.
给出两个整数，返回两个整数的商（用小数表示，对无限循环小数的循环节用括号括起来）
实现除法，正确表示无限循环小数
例如
1/2 = 0.5
1/3 = 0.(3)
-1/3 = -0.(3)
2/1 = 2

为了判断除法过程中有没有出现循环节
需要判断每次取模后的结果，即余数有没有在前面的过程中出现过
如果出现过，找到上一次出现的位置，加上（，末尾加上），就把循环节找出来了
注意整数溢出
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
class Solution_166 {
 public:
  std::string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
      return "0";
    }
    bool negative = false;
    if ((numerator < 0 && denominator > 0) ||
        (numerator > 0 && denominator < 0)) {
      negative = true;
    }
    auto dividend = labs(numerator);
    auto divisor = labs(denominator);
    std::vector<int> mod;   //记录余数
    std::string regular;    //记录商字符串
    bool less = false;      //记录是否整数部分已经除完
    bool addpoint = false;  //记录是否已经添加小数点
    bool level = true;      //添加小数点
    //保证被除数不小于除数
    while (dividend < divisor) {
      mod.push_back(dividend);
      regular.push_back('0');
      if (level) {
        regular.push_back('.');
        addpoint = true;
        level = false;
      }
      dividend *= 10;
    }
    if (negative) {
      regular.insert(0, 1, '-');
    }
    auto remainder = dividend % divisor;  //余数
    auto quotient = dividend / divisor;   //商
    //当余数不为0时继续作除
    while (remainder) {
      //余数出现过，说明开始循环部分
      auto pos = find(mod.begin(), mod.end(), remainder);
      if (pos != end(mod)) {
        //发现余数出现过，先把商加入，根据位置关系找到循环部分
        regular.push_back(quotient + '0');
        auto dot = regular.find('.');
        regular.insert(pos - mod.begin() + dot + 1, 1, '(');
        regular.push_back(')');
        return regular;
      }
      //余数没有出现过，是非循环部分小数
      else {
        //余数小于除数，说明整数部分除完
        if (remainder < divisor) {
          mod.push_back(remainder);
          less = true;
        }
        regular.append(std::to_string(quotient));
        if (less && !addpoint) {
          regular.push_back('.');
          addpoint = true;
        }
      }
      //准备下一轮除法
      if (remainder < divisor) {
        remainder *= 10;
      }
      quotient = remainder / divisor;
      remainder %= divisor;
    }
    //余数为0且商不为-1，说明除尽
    if (!remainder) {
      //当一步就除尽时，商可能大于10，将商转换为字符串
      regular.append(std::to_string(quotient));
    }
    return regular;
  }
};
class Solution_166_back {
 public:
  std::string fractionToDecimal(int numerator, int denominator) {
    int s1 = numerator >= 0 ? 1 : -1;    //被除数是否为正
    int s2 = denominator >= 0 ? 1 : -1;  //除数是否为正
    //转正
    auto dividend = labs(numerator);      //被除数
    auto divisor = labs(denominator);     //除数
    auto quotient = dividend / divisor;   //商
    auto remainder = dividend % divisor;  //余数
    std::unordered_map<long, int> m;
    std::string res = std::to_string(quotient);  //商转为字符串
    //确定商的正负
    if (s1 * s2 == -1 && (quotient > 0 || remainder > 0)) {
      res = "-" + res;
    }
    //一次就能整除则直接返回
    if (remainder == 0) return res;
    res += ".";
    std::string s = "";
    int pos = 0;
    //当余数不为0
    while (remainder != 0) {
      //当余数已经存在时，这个余数第一次出现的地方就是小数开始循环的位置
      if (m.find(remainder) != m.end()) {
        //在开始循环的位置前加上标记，返回
        s.insert(m[remainder], "(");
        s += ")";
        return res + s;
      }
      //键为余数，值为位置
      m[remainder] = pos;
      //作除法，得到的商附到小数部分
      s += std::to_string((remainder * 10) / divisor);
      //得到新的余数
      remainder = (remainder * 10) % divisor;
      //位置递增
      ++pos;
    }
    return res + s;
  }
};
#endif