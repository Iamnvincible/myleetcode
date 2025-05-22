/*
 * @Author: Jie Lin
 * @Date: 2021-04-08 21:14:29
 * @LastEditTime: 2021-04-14 21:42:58
 * @LastEditors: Jie Lin
 * @Description:Solution 34
 * @FilePath: \myleetcode\Search\Solution_34.hpp
 *
 */
#ifndef SOLUTION_34
#define SOLUTION_34
/***
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
 *在升序数组中，找出目标数字所在的开始和结束位置
 *不存在则返回[-1,-1],存在返回具体下标。
 *
 *如果数组中不存在与目标相等的数，返回 [-1,-1].
 * 如果存在，返回最左边下标和最右边下标。
 */
#include <vector>

/***
 * 在有序数组中查找特定元素，使用二分查找，复杂度为log(n)
 * 由于数组中可能会有重复元素，找到后再在目标下标前后搜寻边界
 *
 * 或者，改进二分查找，使之找到的是第一个不大于目标元素的位置，
 * 再找第一个大于目标元素的位置，两个位置之间就是等于目标元素的位置范围
 * 原始二分查找算法在有序数组中寻找目标元素是否存在，没有考虑相同元素存在时，获取这些元素的位置
 *
 */
class Solution_34 {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    int pos1 = searchFisrtNotLarger(nums, target);
    if (pos1 == (int)nums.size() || nums[pos1] != target) {
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

class Solution_34_1 {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    int left = searchBound(nums, target);
    // 需要注意，nums[left] 可能等于目标，不等于目标时不存在满足题意的范围
    // 当 left 等于数组长度时，说明越界，数组中元素都小于目标，可以直接返回；
    // 当 nums[left] 不等于目标，这里只可能大于目标，也直接返回。
    if (left == (int)nums.size() || nums[left] != target) {
      return {-1, -1};
    }
    // 当数组中存在至少一个等于目标的值时，需要找到最右边的下标
    // 将目标值 +1，寻找 >= target + 1 的最小下标位置
    // 再将结果 -1, 就是等于目标的最大下标。
    int right = searchBound(nums, target + 1) - 1;
    return {left, right};
  }

 private:
  /**
  此函数目标是找到一个最小下标 i，使得 nums[i] >= target
  对于闭区间下标值
  在二分查找算法循环结束时，
  如果找到了 nums[i] ≥ target 的值，
  在判断最后一个循环条件时，left 的值即为 i，可能为 nums.size()。
  nums[i] 可能超出数组范围，表示数组中所有元素< target，
  当 i 不越界时，nums[i] 可能 == target，说明目标数存在于数字，
  或者，nums[i] > target，说明数组中所有元素 > target，
  那么 nums[i] >= target.

   */
  int searchBound(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;
    while (left <= right) {  // 只有一个元素时，左右相等需要考虑
      mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
  // 此方法用于寻找右边界
  // 不同的是 if 判断条件是 <= target
  // 在遇到等于目标元素时，下标会一直向后，直到停在第一个大于目标的位置
  // 因此，返回时需要 -1
  int searchBound_r(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;
    while (left <= right) {  // 只有一个元素时，左右相等需要考虑
      mid = left + (right - left) / 2;
      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left - 1;
  }
};
#include <algorithm>
//库函数
class Solution_34_2 {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    auto left = std::lower_bound(nums.begin(), nums.end(), target);
    if (left == nums.end() || *left != target) {
      return {-1, -1};
    }
    // 上界
    //  prev返回迭代器的第n个前驱(n=1)
    auto right = std::prev(std::upper_bound(nums.begin(), nums.end(), target));
    return {int(left - nums.begin()), int(right - nums.begin())};
  }
};
#endif