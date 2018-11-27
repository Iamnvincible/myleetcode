#ifndef SOLUTION_8
#define SOLUTION_8
/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary
until the first non-whitespace character is found. Then, starting from this
character, takes an optional initial plus or minus sign followed by as many
numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral
number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid
integral number, or if no such sequence exists because either str is empty or it
contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.

Assume we are dealing with an environment
which could only store integers
within the 32-bit signed integer range: [−231,  231 − 1].
If the numerical value is out of the range of representable values,
INT_MAX (231 − 1) or INT_MIN (−231) is returned.
字符串转int
1.忽视起始的若干个空格，直到第一个非空格字符
2.可选的+/-符号
3.接着若干个数字，推断为一个数值
4.在若干个数字后的其他字符忽略，不对结果产生影响
5.如果第一个非空格字符之后不是一个有效的整数/字符串为空/只有空格，返回0
6.只处理int32大小的数字，超过范围返回INT_MAX/INT_MIN

需要对各种情况有充分把握
特别注意溢出的判断
 */
#include <climits>
#include <string>
class Solution_8 {
 public:
  int myAtoi(std::string str) {
    int size = str.size();
    int positive = 1;
    int res = 0;
    std::string valid;
    int i = 0;
    //跳过存在的所以空格
    while (str[i] == ' ') {
      i++;
    }
    //判断符号的存在，注意如果有，只能有一个符号
    if (str[i] == '+') {
      i++;
    } else if (str[i] == '-') {
      positive = -1;
      i++;
    } else {
      //这是一段空的else语句块，其实这里的else语句块可以不写
    }
    while (i < size) {
      if (str[i] >= '0' && str[i] <= '9') {
        valid.push_back(str[i++]);
      } else {
        break;
      }
    }
    if (valid.size() > 0) {
      for (int j = 0; j < valid.size(); j++) {
        int val = valid[j] - '0';
        //判断溢出
        //前一步的值大于最大值的1/10必定溢出
        //等于最大值的1/10，判断新来的一位是否大于最大值的最后一位
        //这里只判断了+的部分，负数部分绝对值最大值比正数大1
        //所以大于正的最大值要么到了正数的最大值，要么是负数的最小值
        //判断一下符号即可
        //如果判断负数的余数，注意负数的余数是小于零的！
        //?三元运算符左边结果不等于0即为真，等于0为假，普通的判断也是这样
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && val > INT_MAX % 10)) {
          return positive > 0 ? INT_MAX : INT_MIN;
        } else {
          res = res * 10 + val;
        }
      }
      return res * positive;
    } else {
      return 0;
    }
  }
};
#endif