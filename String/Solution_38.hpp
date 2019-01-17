#ifndef SOLUTION_38
#define SOLUTION_38
/* The count-and-say sequence is the sequence of integers
 with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
给一个数字，数出里面有几个几，
数字序列第一个是1，第二个数前一个数字，
例如:
输入1，返回1
输入2，数前一个数1，里面有1个1，那么返回11
输入3，数第二个数，里面有2个1，那么返回21
依此类推
写一个函数完成给一个数字字符串返回按上面的规则的输出，
1返回1是确定的，把结果存在一个vector里面，取里面的数字，传入自定义函数
把返回值添加到vector，循环到目标数字即可
*/
#include <string>
#include <vector>
class Solution_38 {
 public:
  std::string countAndSay(int n) {
    std::vector<std::string> q = {"1"};
    for (int i = 1; i < n; i++) {
      q.push_back(saynum(q[i - 1]));
    }
    return q[n - 1];
  }
  std::string saynum(std::string num) {
    std::string res;
    // n为遇到的数字，count记录n出现的次数
    int n = 0, count = 0;
    for (auto i = num.begin(); i != num.end(); i++) {
      if (count == 0) {
        n = *i - '0';  //记录数字
        count++;       //计数
      } else if ((*i - '0') == n) {
        count++;
      } else {
        //遇到和前面不一样的数字时先把前的数出来加到字符串中
        res.push_back(count + '0');
        res.push_back(n + '0');
        count = 1;
        n = *i - '0';
      }
    }
    if (count != 0) {
      res.push_back(count + '0');
      res.push_back(n + '0');
    }
    return res;
  }
};
#endif