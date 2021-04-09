/*
 * @Author: Jie Lin
 * @Date: 2021-04-09 22:01:10
 * @LastEditTime: 2021-04-09 22:30:17
 * @LastEditors: Jie Lin
 * @Description:Solution 35
 * @FilePath: \myleetcode\Search\Solution_35.hpp
 *
 */
#ifndef SOLUTION_35
#define SOLUTION_35
/***
 * 在升序数组中寻找目标元素的位置，如果没有则给出目标元素在该数组中可插入并可保持数组升序的位置
 *
 */
#include <vector>
class Solution_35 {
 public:
  int searchInsert(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int pos = end / 2;
    int pre = pos;
    int got = 0;
    while (start <= end) {
      pre = pos;
      if (nums[pos] > target) {
        end = pos - 1;
        pos = start + (end - start) / 2;
      } else if (nums[pos] < target) {
        start = pos + 1;
        pos = start + (end - start) / 2;
      } else {
        got = 1;
        break;
      }
    }
    if (got) {
      return pos;
    } else if (nums[pre] < target) {
      return pre + 1;
    } else {
      return pre;
    }
  }
};
#endif