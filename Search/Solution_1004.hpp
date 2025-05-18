#ifndef SOLUTON_1004
#define SOLUTON_1004
#include <vector>
/*
1004. Max Consecutive Ones III
Given a binary array nums and an integer k,
return the maximum number of consecutive 1's in the array if you can flip at
most k 0's.

求数组中符合条件的最大连续长度，用滑动窗口。
自己想到的方法较为繁琐，
用变量记录 0 变 1 的个数， count
用数组记录 0 变 1 的位置， zeros
两个变量记录 0 变 1 最左边和最右边在数组中的位置，cleft, cright
left 记录窗口最左边 1 的位置，
right 记录最右边 1 的位置，如果是 0 就变 1，变不了就 = left
当 count < k 时可以持续 0 变 1
当 count == k 时，把最左边的 0 变 1 回收，给 right 变。
同时更新 cleft 和 cright.

可以通过，但要考虑清楚。例如 k = 0 的情况。
*/
class Solution_1004 {
 public:
  int longestOnes(std::vector<int>& nums, int k) {
    int result = 0;
    int count = 0;
    std::vector<int> zeros(k);
    int cleft = 0, cright = -1;
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
      if (nums[right]) {
        result = std::max(result, right - left + 1);
      } else {
        if (count < k) {
          result = std::max(result, right - left + 1);
          count++;
          cright++;
          zeros[cright] = right;
        } else if (k > 0) {
          left = zeros[cleft] + 1;
          result = std::max(result, right - left + 1);
          cright = cleft;
          zeros[cright] = right;
          cleft = (cleft + 1) % k;
        } else {
          left = right + 1;
        }
      }
    }

    return result;
  }
};
/*
看到 0x3f 的题解，非常简洁。
对上面的简化，没有过多考虑细节，用通用性来适配。
使用基本的滑动窗口思想，左边一个一个收缩。
同时利用题目特点，用计算取代判断。
记录 0 出现的个数，默认这些都可以变 1。
在不够用时，从左一个一个收缩变过 1 的 0。
这里的过程非常朴素。
直到找到最左边是 1 并满足 k 的位置，更新最大值。
*/
class Solution_1004_1 {
 public:
  int longestOnes(std::vector<int>& nums, int k) {
    int result = 0;
    int left = 0;
    int count = 0;
    for (int right = 0; right < nums.size(); right++) {
      count += (1 - nums[right]);
      while (count > k) {
        count -= (1 - nums[left++]);
      }
      result = std::max(result, right - left + 1);
    }
    return result;
  }
};
#endif