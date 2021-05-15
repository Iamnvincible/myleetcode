/*
 * @Author: Jie Lin
 * @Date: 2021-05-12 22:47:24
 * @LastEditTime: 2021-05-15 19:51:56
 * @LastEditors: Jie Lin
 * @Description:Reverse Integer
 * @FilePath: \myleetcode\ToBDecided\Solution_7.hpp
 *
 */
#ifndef SOLUTION_7
#define SOLUTION_7
/**
 * @brief  将整数反转
 * @note 反转过程中每一步都不能出现溢出
 * @retval None
 */
class Solution_7 {
 public:
  int reverse(int x) {
    int res = 0, mod = 0;
    bool sign = (x > 0);
    while (x) {
      mod = x % 10;
      res = res * 10 + mod;
      x /= 10;
      if (sign) {
        if (x && res > 214748364) {
          return 0;
        }

      } else {
        if (x && res < -214748364) {
          return 0;
        }
      }
    }

    return res;
  }
};
#endif