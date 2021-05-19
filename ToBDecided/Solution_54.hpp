/*
 * @Author: Jie Lin
 * @Date: 2021-05-19 21:47:45
 * @LastEditTime: 2021-05-19 22:36:21
 * @LastEditors: Jie Lin
 * @Description:Spiral Matrix
 * @FilePath: \myleetcode\ToBDecided\Solution_54.hpp
 *
 */
#ifndef SOLUTION_54
#define SOLUTION_54
#include <vector>
/**
 * @brief  给出一个矩阵，逆时针输出各元素
 * @note
 * @retval None
 */
class Solution_54 {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> res;
    int direction = 0;
    int bot = matrix.size() - 1;
    int right = matrix.back().size() - 1;
    int top = 0, left = 0;
    tour(matrix, res, top, bot, left, right, direction);
    // tour2(matrix, res, top, bot, left, right, direction);
    return res;
  }

 private:
  //递归
  void tour(std::vector<std::vector<int>>& matrix, std::vector<int>& res,
            int top, int bot, int left, int right, int direct) {
    if (top > bot || left > right) {
      return;
    }
    if (direct == 0) {
      for (int i = left; i <= right; i++) {
        res.push_back(matrix[top][i]);
      }
      tour(matrix, res, top + 1, bot, left, right, 1);

    } else if (direct == 1) {
      for (int i = top; i <= bot; i++) {
        res.push_back(matrix[i][right]);
      }
      tour(matrix, res, top, bot, left, right - 1, 2);
    } else if (direct == 2) {
      for (int i = right; i >= left; i--) {
        res.push_back(matrix[bot][i]);
      }
      tour(matrix, res, top, bot - 1, left, right, 3);

    } else {
      for (int i = bot; i >= top; i--) {
        res.push_back(matrix[i][left]);
      }
      tour(matrix, res, top, bot, left + 1, right, 0);
    }
  }
  //非递归
  void tour2(std::vector<std::vector<int>>& matrix, std::vector<int>& res,
             int top, int bot, int left, int right, int direct) {
    while (top <= bot && left <= right) {
      if (direct == 0) {
        for (int i = left; i <= right; i++) {
          res.push_back(matrix[top][i]);
        }
        top++;
        direct = 1;

      } else if (direct == 1) {
        for (int i = top; i <= bot; i++) {
          res.push_back(matrix[i][right]);
        }
        right--;
        direct = 2;
      } else if (direct == 2) {
        for (int i = right; i >= left; i--) {
          res.push_back(matrix[bot][i]);
        }
        bot--;
        direct = 3;
      } else {
        for (int i = bot; i >= top; i--) {
          res.push_back(matrix[i][left]);
        }
        left++;
        direct = 0;
      }
    }
  }
};
#endif