/*
 * @Author: Jie Lin
 * @Date: 2021-06-07 22:29:34
 * @LastEditTime: 2021-06-07 22:32:56
 * @LastEditors: Jie Lin
 * @Description:Unique Paths II
 * @FilePath: \myleetcode\DP\Solution_63.hpp
 *
 */
#ifndef SOLUTION_63
#define SOLUTION_63
#include <vector>
/**
 * @brief
 * 在62题基础上，方格中加入了若干障碍，路径不能通过障碍，求有多少种不同的走法
 * 有障碍的格子走法为0
 * @note
 * @retval None
 */
class Solution_63 {
 public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    if (obstacleGrid.back().back() || obstacleGrid[0][0]) return 0;
    int rows = obstacleGrid.size();
    int cols = obstacleGrid.back().size();
    std::vector<std::vector<long>> table(rows, std::vector<long>(cols, 0));
    for (int i = cols - 1; i >= 0; i--) {
      if (obstacleGrid.back()[i] != 1) {
        table.back()[i] = 1;
      } else {
        for (int j = i; j >= 0; j--) {
          table.back()[j] = 0;
        }
        break;
      }
    }
    for (int i = rows - 1; i >= 0; i--) {
      if (obstacleGrid[i].back() != 1) {
        table[i].back() = 1;
      } else {
        for (int j = i; j >= 0; j--) {
          table[j].back() = 0;
        }
        break;
      }
    }
    for (int i = rows - 2; i >= 0; i--) {
      for (int j = cols - 2; j >= 0; j--) {
        long right = obstacleGrid[i][j + 1] ? 0 : table[i][j + 1];
        long botto = obstacleGrid[i + 1][j] ? 0 : table[i + 1][j];
        table[i][j] = right + botto;
      }
    }
    return table[0][0];
  }
};
#endif