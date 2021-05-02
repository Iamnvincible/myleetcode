/*
 * @Author: Jie Lin
 * @Date: 2021-05-02 23:11:25
 * @LastEditTime: 2021-05-02 23:49:30
 * @LastEditors: Jie Lin
 * @Description:Maximum Subarray
 * @FilePath: \myleetcode\DP\Solution_53.hpp
 *
 */
#ifndef SOLUTION_53
#define SOLUTION_53
#include <algorithm>
#include <vector>
class Solution_53 {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int max = INT_MIN;  //记录最大连续子数组的和
    int curSum = 0;     //记录当前子数组的和
    for (auto&& item : nums) {
      //遍历数组
      //如果遇到的下一个数字能够让当前子数组的和增加,
      //那么将这个数字加入当当前子数组中，并计算加入后的和
      //如果当前子数组的和加入新数字后还没有新数字大，当前子数组值为负，当前子数组对组成最大连续子数组无益，需要放弃
      //那么新数字可成为新子数组的起始元素
      curSum = std::max(curSum + item, item);
      //取 更新子数组后的和 与 之前最大连续子数组和 的最大值
      max = std::max(max, curSum);
    }
    return max;
  }
};
#endif