#ifndef SOLUTION_209
#define SOLUTION_209
#include <vector>
/*
209. Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target,
return the minimal length of a whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.
*/
// sliding window
// 起始窗口为1，向右寻找第一个满足要求的位置
// 而后尝试从左边缩小窗口，直到不满足条件
// 继续向右扩展，重复上一步，直到遍历完成
// 外层循环从左到右，一共 n 次
// 内层循环一共也是 n 次，总体 O(n)
class Solution_209 {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int size = nums.size();
    int result = size + 1;
    int i = 0;  // left
    int sum = 0;
    // right
    for (int j = 0; j < size; j++) {
      sum += nums[j];
      while (sum >= target) {
        result = std::min(result, j - i + 1);
        sum -= nums[i++];
      }
    }
    return result < size + 1 ? result : 0;
  }
};
// 此方法遇到较大数据量时会超时
// 先找到第一个满足条件的长度，随后按这个长度为上界，向右寻找
// 从左边缩短窗口，并将上一次找到的最短长度作为结束条件，可以减少搜索空间
// 但由于内层循环以 i 作为开始条件，没有利用上一次计算 i,j 之间 sum 的计算结果，
// 使得重复计算很多中间值。
// 虽然循环结束条件有所优化，但整体为 n^2/2->O(n^2)。
class Solution_209_2 {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int size = nums.size();
    int result = size + 1;
    for (int i = 0; i < size; i++) {
      int sum = 0;
      for (int j = i; (j - i + 1) < (result) && j < size; j++) {
        sum += nums[j];
        if (sum >= target) {
          if (j - i + 1 <= result) {
            result = j - i + 1;
          }
          break;
        }
      }
    }
    return result < size + 1 ? result : 0;
  }
};
// 此方法给上面的循环打了补丁，解决了中间值重复计算的问题
// 但是为了处理左边缩小窗口的变化，需要较为繁琐的设计
// 总体复杂度减少到 O(n)。
// 只用作对上面方法可行性的验证。
// 分析与滑动窗口方法的区别，以掌握滑动窗口的技巧
class Solution_209_2_1 {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int size = nums.size();
    int result = size + 1;
    int sum = 0;
    int lastj = 0;
    int back = 1;
    for (int i = 0; i < size; i++) {
      if (sum > 0 && sum < target && lastj == size - 1) break;
      for (int j = lastj; (j - i + 1) < (result) && j < size; j++) {
        if (back) sum += nums[j];
        if (sum >= target) {
          if (j - i + 1 <= result) {
            result = j - i + 1;
          }
          sum -= nums[i];
          back = 0;
          lastj = j;
          break;
        }
        if (j - i + 2 == result) {
          sum -= nums[i];
          back = 0;
          lastj = j;
          break;
        }
        lastj = j;
        back = 1;
      }
    }
    return result < size + 1 ? result : 0;
  }
};
#endif