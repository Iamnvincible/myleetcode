/*
 * @Author: Jie Lin
 * @Date: 2021-06-10 21:26:20
 * @LastEditTime: 2021-06-10 21:47:56
 * @LastEditors: Jie Lin
 * @Description:Minimum Path Sum
 * @FilePath: \myleetcode\DP\Solution_64.hpp
 *
 */

#ifndef SOLUTION_64
#define SOLUTION_64
#include <vector>
/**
 * @brief
 * 62、63题的延申。方格中每个格子都有一个路径权值，求从左上到右下所有路径中最小的权值和。
 * @note
 * 从终点出发，计算从某一个格子开始走，走到终点的最小权值和
 * 定义一个数组，表示一行上每个格子走到终点的最小权值和
 * @retval None
 */
class Solution_64 {
 public:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.back().size();
    std::vector<int> cost(cols, 0);
    for (int i = rows - 1; i >= 0; i--) {
      for (int j = cols - 1; j >= 0; j--) {
        if (j == cols - 1) {
          //处理最右边一列
          cost[j] = cost[j] + grid[i][j];
        } else if (i == rows - 1) {
          //处理最下面一行
          cost[j] = cost[j + 1] + grid[i][j];
        } else {
          int min = cost[j] > cost[j + 1] ? cost[j + 1] : cost[j];
          cost[j] = grid[i][j] + min;
        }
      }
    }
    return cost[0];
  }
};
#endif
