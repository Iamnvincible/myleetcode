/*
 * @Author: Jie Lin
 * @Date: 2021-05-20 21:27:23
 * @LastEditTime: 2021-05-20 21:59:59
 * @LastEditors: Jie Lin
 * @Description:Spiral Matrix II
 * @FilePath: \myleetcode\ToBDecided\Solution_59.hpp
 *
 */
#ifndef SOLUTION_59
#define SOLUTION_59
#include <vector>
/**
 * @brief  在nxn的空矩阵中，顺时针填满1-n*n的数字
 * @note  类似54题
 * @retval None
 */
class Solution_59 {
 public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> res(n, std::vector<int>(n));
    int num = 1;
    int left = 0, top = 0;
    int right = n - 1, bot = n - 1;
    int dir = 0;
    while (num <= n * n) {
      if (dir == 0) {
        for (int i = left; i <= right; i++) {
          res[top][i] = num++;
        }
        top++;
        dir = 1;
      } else if (dir == 1) {
        for (int i = top; i <= bot; i++) {
          res[i][right] = num++;
        }
        right--;
        dir = 2;
      } else if (dir == 2) {
        for (int i = right; i >= left; i--) {
          res[bot][i] = num++;
        }
        bot--;
        dir = 3;
      } else {
        for (int i = bot; i >= top; i--) {
          res[i][left] = num++;
        }
        left++;
        dir = 0;
      }
    }

    return res;
  }
};
#endif