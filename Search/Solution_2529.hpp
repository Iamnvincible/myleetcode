#ifndef SOLUTION_2529
#define SOLUTION_2529
/*
Given an array `nums` sorted in non-decreasing order,
return the maximum between the number of
positive integers and the number of negative integers.

In other words,
if the number of positive integers in `nums` is `pos` and
the number of negative integers is `neg`,
then return the maximum of `pos` and `neg`.

Note that 0 is neither positive nor negative.

在升序数组中，计数正数和负数的数量，返回两者较大的值
0 不是整数，也不是负数
---
尽管可以遍历一遍得到正数和负数的数量，但需要 O(n) 的复杂度。
由于数组已经升序排列，使用二分查找可以降低到 O(logn)。

在 34 Find First and Last Position of Element in Sorted Array 题中，
编写过查找特定目标数字在数组中的左右边界，
在这里可以复用这个函数。
由于数组中可能有 0，那么要获得正数和负数的数量可以查找 0 的左右边界。
比 0 小的左边都是负数，比 0 大的一边都是正数。

查找函数返回的是第一个不大于目标数的位置，
如果返回 0 说明所有元素都大于目标数，
返回原数组长度，说明所有元素都小于目标数。

当查找 0 时，如果返回 0，说明数组非负，这个0 也同时代表了负数的数量！
而返回正数时，这个正数就是数组中负数的数量：
    返回大于 0 的数时，这个位置指示了第一个非负数的位置，
        同时也是负数的数量。
        全为负数时，返回的是数组长度，也就是负数的数量；

为了获得正数的数量，需要直到第一个 > 0 的数字的位置。
而查找 0 是获得 0 的左边界，要获得右边界需要查找 1，
即查找 1 的左边界，也就是第一个大于 0 的数的位置。

当返回正数时，获得第一个正数的位置，用数组长度减去这个数就是正数的数量；
当返回 0 时，说明整个数组都是正数，数组长度减去 0，仍是整个数组长度。
*/
#include <vector>
class Solution_2529 {
 public:
  int maximumCount(std::vector<int>& nums) {
    int minus = searchBound(nums, 0);
    int plus = nums.size() - searchBound(nums, 1);
    return minus > plus ? minus : plus;
  }
  // 二分，找到[最小的]不大于 target 的数组下标
  // 如果所有元素都小于 target， 返回 nums.size()
  // 如果所有元素都大于 target，返回 0
  int searchBound(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }
};
#endif