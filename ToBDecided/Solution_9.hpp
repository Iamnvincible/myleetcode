/*
 * @Author: Jie Lin
 * @Date: 2021-05-13 22:04:55
 * @LastEditTime: 2021-05-15 19:27:54
 * @LastEditors: Jie Lin
 * @Description:Palindrome Number
 * @FilePath: \myleetcode\ToBDecided\Solution_9.hpp
 *
 */
#ifndef SOLUTION_9
#define SOLUTION_9
#include <vector>
/**
 * @brief  判断回文数字
 * @note
 * @retval None
 */
class Solution_9 {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    std::vector<int> nums;
    while (x) {
      nums.push_back(x % 10);
      x /= 10;
    }
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      if (nums[left++] != nums[right--]) {
        return false;
      }
    }
    return true;
  }
};
class Solution_9_2 {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int copy = x;
    int divisor = 1;
    while (copy >= 10) {
      divisor *= 10;
      copy /= 10;
    }
    while (divisor) {
      int quotient = x / divisor % 10;
      int remainder = x % 10;
      if (quotient != remainder) return false;
      x /= 10;
      divisor /= 100;
    }
    return true;
  }
};
#endif