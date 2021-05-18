/*
 * @Author: Jie Lin
 * @Date: 2021-05-18 10:02:06
 * @LastEditTime: 2021-05-18 10:04:12
 * @LastEditors: Jie Lin
 * @Description:Pascal's Triangle II
 * @FilePath: \myleetcode\ToBDecided\Solution_119.hpp
 *
 */
#ifndef SOLUTION_119
#define SOLUTION_119
#include <vector>
/**
 * @brief  计算杨辉三角的某一行
 * @note   只用一个数组，下一行的数组复用这一行的数据，从后往前算，以免覆盖
 * @retval None
 */
class Solution_119 {
 public:
  std::vector<int> getRow(int rowIndex) {
    std::vector<int> res(rowIndex + 1, 1);
    for (int i = 3; i <= rowIndex + 1; i++) {
      for (int j = i - 2; j > 0; j--) res[j] = res[j] + res[j - 1];
    }
    return res;
  }
};
#endif