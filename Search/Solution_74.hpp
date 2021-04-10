/*
 * @Author: Jie Lin
 * @Date: 2021-04-10 19:18:03
 * @LastEditTime: 2021-04-10 19:47:53
 * @LastEditors: Jie Lin
 * @Description:Solution 74
 * @FilePath: \myleetcode\Search\Solution_74.hpp
 *
 */
/**
 * @brief  在矩阵里找目标元素
 * @note
 * 二分查找，把矩阵当成是一维数组，注意处理整体的二分位置下标在矩阵中的索引位置
 */
#include <vector>
class Solution_74 {
 public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int rows = matrix.size();
    int cols = matrix.front().size();
    int start = 0;
    int end = rows * cols - 1;
    while (start <= end) {
      int pos = start + (end - start) / 2;
      int value = matrix[pos / cols][pos % cols];
      if (value > target) {
        end = pos - 1;
      } else if (value < target) {
        start = pos + 1;
      } else {
        return true;
      }
    }
    return false;
  }

 private:
  bool biSearch(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
      int pos = start + (end - start) / 2;
      if (nums[pos] > target) {
        end = pos - 1;
      } else if (nums[pos] < target) {
        start = pos + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};