#ifndef SOLUTION_713
#define SOLUTION_713
#include <vector>
/*
713. Subarray Product Less Than K
Given an array of integers nums and an integer k,
return the number of contiguous subarrays
where the product of all the elements in the subarray is strictly less than k.

比较 209. 计算和>=目标的最小长度
本地计算乘积严格小于目标的子数组总数
滑动窗口方法同样适用，也就是同向双指针，区别于相向双指针
因为滑动窗口可以在一次遍历中枚举到所有符合条件的连续数组
本题在窗口缩小上稍有变化
固定窗口右端点，如果窗口乘积小于目标，
那么所有左边以此端点作为因数的连续数组的乘积都小于目标，累加长度即可。
当窗口乘积大于等于目标时，需要从左边缩小窗口。
即从乘积中除以左端点，直到窗口乘积再次小于目标。
*/
class Solution_713 {
 public:
  int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    int result = 0;
    if (k <= 1) return result;
    int left = 0;
    int product = 1;
    for (int right = 0; right < nums.size(); right++) {
      product *= nums[right];
      while (product >= k) {
        product /= nums[left++];
      }
      result += (right - left + 1);
    }
    return result;
  }
};

#endif