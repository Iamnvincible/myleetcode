/*
 * @Author: Jie Lin
 * @Date: 2021-05-17 22:24:32
 * @LastEditTime: 2021-05-17 22:25:20
 * @LastEditors: Jie Lin
 * @Description:Pascal's Triangle
 * @FilePath: \myleetcode\ToBDecided\Solution_118.hpp
 *
 */
#ifndef SOLUTION_118
#define SOLUTION_118
#include <vector>
class Solution_118 {
 public:
  vector<vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res(numRows);
    for (int i = 1; i <= numRows; i++) {
      std::vector<int> row(i, 1);
      for (int j = 1; j < i - 1; j++) {
        row[j] = res[i - 2][j - 1] + res[i - 2][j];
      }
      res[i - 1] = row;
    }
    return res;
  }
};
#endif