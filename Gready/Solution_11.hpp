/*
 * @Author: Jie Lin
 * @Date: 2021-04-29 22:30:14
 * @LastEditTime: 2021-04-29 23:16:13
 * @LastEditors: Jie Lin
 * @Description:Container With Most Water
 * @FilePath: \myleetcode\Gready\Solution_11.hpp
 *
 */
#ifndef SOLUTION_11
#define SOLUTION_11
#include <algorithm>
#include <vector>
/**
 * @brief
 * 给出一个数组，数组值表示所在位置条形柱的高度，求两个柱子之间储水的最大值
 * @note
 * 从两边向中间寻找最大值
 * @retval None
 */
class Solution_11 {
 public:
  int maxArea(std::vector<int>& height) {
    int most = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
      int left_height = height[left];
      int right_height = height[right];
      //计算左右两个柱子之间的储水量
      int size = (right - left) * std::min(left_height, right_height);
      //取较大值
      most = std::max(most, size);
      //因为水桶原理，水桶储水量由最短的板决定，所以应该先固定较高的板，由较短的板向内移动才能保守（贪婪）地求最大值
      //当然可能移动后变得更短，移动后不一定能获得更大的储水量
      //不过已经保存了most，可以在剩下的“机会”中继续遍历来寻找可能存在的更大值
      if (left_height < right_height) {
        left++;
      } else {
        right--;
      }
    }
    return most;
  }
};
#endif