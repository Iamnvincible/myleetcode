/*
 * @Author: Jie Lin
 * @Date: 2021-05-24 21:26:40
 * @LastEditTime: 2021-05-24 21:31:36
 * @LastEditors: Jie Lin
 * @Description:Two Sum II - Input array is sorted
 * @FilePath: \myleetcode\Search\Solution_167.hpp
 *
 */
#ifndef SOLUTION_167
#define SOLUTION_167
#include <vector>
/**
 * @brief
 * 给出一个升序数组和一个目标数，寻找两个数组中的数，使得和为目标数，返回两个目标数的下标（以1为起点）
 * @note
 * 给出的数组有序，可以使用二分查找
 * 遍历数组，寻找目标数和当前遍历数的差是否在数组中
 * @retval None
 */
class Solution_167 {
 public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> res(2);
    for (int i = 0; i < numbers.size(); i++) {
      int index = bisect(i + 1, numbers, target - numbers[i]);
      if (index != -1) {
        res[0] = i + 1;
        res[1] = index + 1;
        break;
      }
    }
    return res;
  }

 private:
  /**
   * @brief  给出起点的二分查找
   * @note
   * @param  start:二分查找的数组起点位置
   * @param  numbers:升序数组
   * @param  remainder:查找元素
   * @retval 如果找到，返回查找元素的下标，否则返回-1
   */
  int bisect(int start, std::vector<int>& numbers, int remainder) {
    int left = start;
    int right = numbers.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (numbers[mid] == remainder) {
        return mid;
      } else if (numbers[mid] > remainder) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};
#endif