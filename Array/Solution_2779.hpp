#ifndef SOLUTION_2779
#define SOLUTION_2779
/**
You are given a 0-indexed array nums and a non-negative integer k.

In one operation, you can do the following:
1. Choose an index i
    that hasn't been chosen before from the range [0,nums.length - 1].
2. Replace nums[i] with any integer
    from the range [nums[i] - k,nums[i] + k].

The beauty of the array is the length of the longest subsequence consisting of
equal elements.

Return the maximum possible beauty of the array nums after applying the
operation any number of times.

Note that you can apply the operation to each index only once.

A subsequence of an array is a new array generated from the original array
by deleting some elements (possibly none) without changing the order of the
remaining elements.

给出整数数组 nums 和非负整数 k

可以对数组执行这样的操作：
1. 选出一个前面尚未选择过的位置 i，
2. 将这个位置的值调整为 nums[i] - k, nums[i] +k 之间的值

定义美丽值，数组中相同值的数量的最大值
求，在对数组执行若干次操作后能够得到的最长美丽值

子序列指的是从原数组中按次序挑选若干个值组成的数组
---
滑动窗口解法
由操作的定义可知，每个元素的范围可以变到 value - k, value + k 之间，
要使美丽值大，需要让更多个元素变到一个相同的值。

由于题目不要求给出具体执行操作的位置，只要给出最大的值。
因此可以对原数组排序，
较小的一端可以变化的最大值与较大一端可变化的最小值控制这段元素之间变化的值。

在升序数组中挑选左右两个值，
只要较小的数可变到最大值[不小于]较大的数可变的最小值，
这两个数字之间的数字就可以变化到同一个值。
有序数组可以很好地处理这个问题。

据此可以执行滑动窗口，获得满足这个条件的最长距离。
新元素进入窗口，计算是否满足条件，满足则更新最长值。
否则从左缩小窗口。

*/
#include <algorithm>
#include <vector>

class Solution_2779 {
 public:
  int maximumBeauty(std::vector<int>& nums, int k) {
    int res = 1;
    std::sort(nums.begin(), nums.end());
    int left = 0, right = 1;
    int size = nums.size();
    while (right < size) {
      int max = nums[left] + k;   // 左边最大值
      int min = nums[right] - k;  // 右边最小值
      if (max >= min) {
        res = std::max(res, right - left + 1);
      } else {
        left++;
      }
      right++;
    }
    return res;
  }
};
#endif

// 6 8 3  4
// 2 4 -1 0