/*
 * @Author: Jie Lin
 * @Date: 2021-04-09 22:01:10
 * @LastEditTime: 2021-04-10 20:09:51
 * @LastEditors: Jie Lin
 * @Description:Solution 35
 * @FilePath: \myleetcode\Search\Solution_35.hpp
 *
 */
#ifndef SOLUTION_35
#define SOLUTION_35
/***
 * 在升序数组（不重复）中寻找目标元素的位置，如果没有则给出目标元素在该数组中可插入并可保持数组升序的位置
 *二分查找，如果找到就返回找到的位置
 */
#include <vector>
class Solution_35 {
 public:
  int searchInsert(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
      int pos = start + (end - start) / 2;
      int value = nums[pos];
      if (value == target) {
        return pos;
      } else if (value > target) {
        end = pos - 1;
      } else {
        start = pos + 1;
      }
    }
    return start;
  }
};
#endif