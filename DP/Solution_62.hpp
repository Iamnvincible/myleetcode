/*
 * @Author: Jie Lin
 * @Date: 2021-06-06 21:34:13
 * @LastEditTime: 2021-06-06 21:56:00
 * @LastEditors: Jie Lin
 * @Description:Unique Paths
 * @FilePath: \myleetcode\DP\Solution_62.hpp
 *
 */
#ifndef SOLUTION_62
#define SOLUTION_62
#include <vector>
/**
 * @brief
 * 给出mxn方格，从左上角一步一步移动到右下角，每次只能往右或往下走一步，一共有多少种走法
 * @note
 * 只有一行或一列的时候只有一种走法
 * 动态规划数组mxn，最后一行，最后一列走到右下角都只有一种走法，
 * 其他位置走到右下角的走法数目等于它下面一格和右边一格走法的和，
 * 从右往左，从下往上依次计算数组中的数值，
 * 最后计算得到数组第一行第一列的值，也就是从左上角走到右下角的走法数目
 * @retval None
 */
class Solution_62 {
 public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> table(m - 1, std::vector<int>(n));
    for (auto &&item : table) {
      item.back() = 1;
    }
    table.push_back(std::vector<int>(n, 1));
    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        table[i][j] = table[i + 1][j] + table[i][j + 1];
      }
    }
    return table[0][0];
  }
};
//简化一下，其实只需要一个长为n的数组即可
class Solution_62_2 {
 public:
  int uniquePaths(int m, int n) {
    std::vector<int> row(n, 1);
    for (size_t i = 1; i < m; i++) {
      for (int j = n - 2; j >= 0; j--) {
        row[j] = row[j] + row[j + 1];
      }
    }
    return row[0];
  }
};
#endif