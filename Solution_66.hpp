#ifndef SOLUTION_66
#define SOLUTION_66
/* Given a non-empty array of digits representing a non-negative integer,
plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list,
and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero,
except the number 0 itself.
对一个vector<int>代表的长整数+1
处理好进位，最高位会不会进位
可以再初始化一个vector
或者在digits上直接操作
*/
#include <vector>
class Solution_66 {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    std::vector<int> res(digits.size() + 1, 0);
    int add = 0;
    res[digits.size()] = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      auto num = digits[i];
      auto temp = res[i + 1] + num + add;
      add = temp / 10;
      res[i + 1] = temp % 10;
    }
    if (add == 1) {
      res[0] = 1;
    } else {
      res.erase(res.begin(), res.begin() + 1);
    }
    return res;
  }
};
class Solution_66 {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    int add = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      auto num = digits[i];
      auto temp = num + add;
      add = temp / 10;
      digits[i] = temp % 10;
    }
    if (add == 1) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};
#endif