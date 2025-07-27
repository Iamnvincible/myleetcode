#ifndef SOLUTION_2962
#define SOLUTION_2962
/*
You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at
least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

整数数组 nums，正数 k
返回子数组的数量

子数组满足：
  原数组中的最大值元素在子数组中至少出现 k 次
子数组是原数组中的连续部分

---
先找出原数组最大值

滑动窗口解法：
新元素加入窗口，判断是否满足子数组条件，
不满足则继续扩展窗口。

当窗口构成的子数组满足条件，
这个子数组本身可以作为 1 实例，
窗口左则不在窗口中的元素数量都可以加入到窗口中，作为 left 个实例。
共计增加 left + 1 个实例。
为了能够在后续窗口扩展中利用这个性质，
缩小窗口左端，直到窗口内的子数组不满足条件，可以继续扩展窗口回到第一步的状态。
此时的 left 就是所有左端元素的个数 + 1。
（在 left 非 0 时，窗口左端应当就是一个最大值元素，
left == 0 时，窗口左端缩小到第一个最大值元素的右侧第一个元素）


*/
#include <algorithm>
#include <vector>
class Solutio_2962 {
 public:
  long long countSubarrays(std::vector<int>& nums, int k) {
    long long res = 0;
    int size = nums.size();
    int max_element = *std::max_element(nums.begin(), nums.end());
    int left = 0, right = 0;
    int count = 0;
    while (right < size) {
      int val = nums[right];
      count += (val == max_element);
      while (count == k) {
        count -= nums[left++] == max_element;
      }
      res += left;
      right++;
    }
    return res;
  }
};

#endif