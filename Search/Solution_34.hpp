/*
 * @Author: Jie Lin
 * @Date: 2021-04-08 21:14:29
 * @LastEditTime: 2021-04-10 20:46:59
 * @LastEditors: Jie Lin
 * @Description:leetcode 34
 * @FilePath: \myleetcode\Search\Solution_34.hpp
 *
 */
#ifndef SOLUTION_34
#define SOLUTION_34
/***
 *在升序数组中，找出目标数字所在的开始和结束位置
 *不存在返回[-1,-1],存在返回具体下标。
 *
 *
 */
#include <vector>

/***
 * 在有序数组中查找特定元素，使用二分查找，复杂度为log(n)
 * 由于数组中可能会有重复元素，找到后再在目标下标前后搜寻边界
 * 或者，改进二分查找，使之找到的是第一个不大于目标元素的位置，再找第一个大于目标元素的位置，两个位置之间就是等于目标元素的位置范围
 */
class Solution_34 {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    int pos1 = searchFisrtNotLarger(nums, target);
    if (pos1 == nums.size() || nums[pos1] != target) {
      return {-1, -1};
    }
    int pos2 = searchFisrtNotLarger(nums, target + 1) - 1;
    return {pos1, pos2};
  }

 private:
  int searchFisrtNotLarger(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
      int pos = start + (end - start) / 2;
      int value = nums[pos];
      if (value >= target) {
        end = pos - 1;
      } else {
        start = pos + 1;
      }
    }
    return start;
  }
};
#include <algorithm>
#include <iterator>

// to be continued
class Solution_34_stl {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    //下界
    const int l = std::distance(
        nums.begin(), std::lower_bound(nums.begin(), nums.end(), target));
    //上界
    // prev返回迭代器的第n个前驱(n=1)
    const int u = std::distance(
        nums.begin(),
        std::prev(std::upper_bound(nums.begin(), nums.end(), target)));
    if (nums[l] != target)  // not found
      return std::vector<int>{-1, -1};
    else
      return std::vector<int>{l, u};
  }
};

// O(n)的办法
class Solution_34_bak {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    std::vector<int> res{-1, -1};
    int flag = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] == target) {
        if (!flag) {
          flag = 1;
          res[0] = res[1] = i;

        } else
          res[1] = i;
      }
    }
    return res;
  }
};

#endif