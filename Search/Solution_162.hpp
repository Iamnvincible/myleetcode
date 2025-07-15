#ifndef SOLUTION_162
#define SOLUTION_162
/*
162. Find Peak Element
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words,
an element is always considered to be strictly greater than a neighbor that is
outside the array.

You must write an algorithm that runs in O(log n) time.
nums[i] != nums[i + 1] for all valid i.

寻找数组中的极大值
数组中相邻元素不相等，且认为数组外为无穷小。

学习 0x3f 的证明，有
如果 nums[i] > nums[i+1]，那么在 [0,i] 中一定存在极大值。
如果 nums[i] < nums[i+1], 那么在 [i+1,n-1] 中一定存在极大值。
可以想象成数学函数图像，对函数求极大值。
虽然数组不是连续的，可以类比。
连续可导函数，要求极大值
取连续的两个点，极大值在更大的一个点的那边一定存在。
小的那边不一定存在，例如左边点那边单调递增，右边点也单调递增。

可以用二分的思想，比较连续两个点的大小，快速地向有答案的一半数组上继续寻找。
左右下标相等时即为极大值点。
*/
#include <vector>
class Solution_162 {
 public:
  int findPeakElement(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      // 这里不会越界，假设越界 mid = n - 1
      // 数组内不同下标之和平均不会得到 n - 1
      if (nums[mid] > nums[mid + 1]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

#endif
