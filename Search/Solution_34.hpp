/*
 * @Author: Jie Lin
 * @Date: 2021-04-08 21:14:29
 * @LastEditTime: 2021-04-09 22:30:52
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
 */
class Solution_34 {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    std::vector<int> res{-1, -1};
    int size = nums.size();
    if (size == 0) {
      return res;
    }
    int got = 0;
    int start = 0;
    int end = size - 1;
    int pos = end / 2;
    int pre = -1;
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
    if (!got) {
      return res;
    }
    while (pos <= end) {
      if (nums[pos] == target) {
        pos++;
      } else {
        break;
      }
    }
    res[1] = pos - 1;
    while (pre >= start) {
      if (nums[pre] == target) {
        pre--;
      } else {
        break;
      }
    }
    res[0] = pre + 1;
    return res;
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