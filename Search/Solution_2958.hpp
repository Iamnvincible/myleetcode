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
最长子数组，子数组中，每个数字[0-9]出现的次数小于k
滑动窗口解法
用哈希表记录 0-9 每个数字在子数组中出现的次数。
窗口向右滑动，新数字加入子数组（窗口）。
如果加入后，数字出现次数没有超过 k，这是满足要求的数组，更新最长值；
如果数字大于 k，说明此时窗口（子数组）不符合要求，
如果不做操作，继续扩展一定也不符合要求。
为使窗口符合要求，从左边缩小窗口。缩小时将数字出现次数递减。
注意，在这个循环中，是新加入窗口右侧的数字使得窗口不符合要求，
那么结束条件就是这个数字出现的次数不再大于 k。
*/
class Solution_2958 {
 public:
  int maxSubarrayLength(std::vector<int>& nums, int k) {
    int result = 1;
    std::unordered_map<int, int> record;
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
      record[nums[right]]++;
      while (record[nums[right]] > k) {
        record[nums[left++]]--;
      }
      result = std::max(result, right - left + 1);
    }
    return result;
  }
};
#endif