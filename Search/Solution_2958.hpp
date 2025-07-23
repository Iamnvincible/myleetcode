#ifndef SOLUTION_2958
#define SOLUTION_2958
#include <unordered_map>
#include <vector>
/*
2958. Length of Longest Subarray With at Most K Frequency
You are given an integer array nums and an integer k.
The frequency of an element x is the number of times it occurs in an array.
An array is called good if the frequency of each element in this array is less
than or equal to k. Return the length of the longest good subarray of nums. A
subarray is a contiguous non-empty sequence of elements within an array.
最多 K 个重复元素的最长子数组

给出一个整数数组 nums，一个整数 k

假设，一个数组中某个元素出现的次数为这个元素的频率
当一个数组中每个元素出现的次数不超过 k 时，称这个数组是好数组

在数组 nums 的子数组中，找出最长的好数组，返回这个数组的长度。
注意频率是对于一个子数组中的元素，而不是整个 nums 数组。

滑动窗口解法
用哈希表记录元素在子数组中出现的次数。
窗口向右滑动，新数字加入子数组（窗口）。
如果加入后，子数值中新加入数字出现次数没有超过
k，这是满足要求的数组，更新最长值；

如果新加入数字的频率大于 k，说明此时窗口（子数组）不符合要求，
如果不做操作，继续扩展一定也不符合要求。
为使窗口符合要求，从左边缩小窗口。缩小时将数字出现次数递减。

注意，在这个循环中，是新加入窗口右侧的数字使得窗口不符合要求，
那么结束条件就是这个数字出现的次数不再大于 k。
*/
class Solution_2958 {
 public:
  int maxSubarrayLength(std::vector<int>& nums, int k) {
    int left = 0, right = 0;
    int size = nums.size();
    int max = 1;
    std::unordered_map<int, int> record;
    while (right < size) {
      int value = nums[right];
      record[value]++;
      while (record[value] > k) {
        record[nums[left]]--;
        left++;
      }
      max = std::max(max, right - left + 1);
      right++;
    }
    return max;
  }
};
#endif