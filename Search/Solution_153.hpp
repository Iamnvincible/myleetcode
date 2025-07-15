#ifndef SOLUTION_153
#define SOLUTION_153
/*
153. Find Minimum in Rotated Sorted Array
Suppose an array of length n sorted in ascending order is rotated between 1 and
n times.
For example, the array nums = [0,1,2,4,5,6,7] might become:

    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements,
return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
把一个升序数组向右移动，移出元素从左边进入。
要求对数复杂度，适用二分查找思想。
比较中间元素和最右边元素大小，
如果大于，说明左边已经移入了至少一半较大的元素，最小元素应该在右侧。
如果中间小于最右侧，说明左边移入较大元素还没到一半，最小元素应该在左侧。
*/
#include <vector>
class Solution_153 {
 public:
  int findMin(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      int m = nums[mid];
      int r = nums[right];
      if (m < r) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return nums[left];
  }
};
#endif