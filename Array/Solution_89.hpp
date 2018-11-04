#ifndef SOLUTION_89
#define SOLUTION_89
/* The gray code is a binary numeral system
where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the
code, print the sequence of gray code. A gray code sequence must begin with 0.
格雷码
一种相邻数字只差一个二进制位的循环码
第一个数是0，
第1步.变动最后一位（取反）；
第2步.变动从右起第一个1的左边一位；
重复以上两步，获得2^n个数字

n位的格雷码可以在n-1位格雷码基础上，对n-1个数字reverse，获得n个数字
前n-1个数字前面加0，后n-1个数字前面加1
用递归做

还有种方法用位运算，令人拍案叫绝
第i个数计算方法为：i异或i/2
*/

#include <algorithm>
#include <vector>
class Solution_89 {
 public:
  std::vector<int> grayCode(int n) {
    std::vector<int> res;
    if (n == 0) {
      res.push_back(n);
    } else {
      for (int i = 0; i < (1 << n); i++) {
        res.push_back(i ^ (i >> 1));
      }
    }
    return res;
  }
};
class Solution_89_bak {
 public:
  std::vector<int> grayCode(int n) {
    if (n == 0) {
      return {0};
    } else if (n == 1) {
      return {0, 1};
    } else {
      auto res = grayCode(n - 1);
      std::vector<int> rev(res.size());
      std::reverse_copy(begin(res), end(res), rev.begin());
      res.insert(res.end(), rev.begin(), rev.end());
      for (int i = res.size() / 2; i < res.size(); i++) {
        res[i] += pow(2, n - 1);
      }
      return res;
    }
  }
};
#endif