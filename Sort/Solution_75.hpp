#ifndef SOLUTION_75
#define SOLUTION_75
/*
Given an array with n objects colored red, white or blue, sort them in-place so
that objects of the same color are adjacent, with the colors in the order red,
white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white,
and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.
数组中只有0，1，2三种数字
对数组排序使得所有数字0在数组的前面，2在后面，1在中间
不要使用stl的排序
 */
#include <algorithm>
#include <functional>
#include <vector>
/*
法一，计数
记录0，1，2出现的个数
再遍历一次把对应次数的0，1，2赋值给数组元素即可
 */
class Solution_75 {
 public:
  void sortColors(std::vector<int>& nums) {
    int count[] = {0, 0, 0};
    for (auto i : nums) {
      count[i]++;
    }
    int k = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < count[i]; j++) {
        nums[k++] = i;
      }
    }
  }
};
/*
法二
双指针法
用两个变量记录0，2的下标边界
通过交换的办法使得边界两侧的数字满足要求
中间剩下的就是1
 */
class Solution_75_back {
 public:
  void sortColors(std::vector<int>& nums) {
    int red = 0;  //数字0 红色部分的最后一个下标的下一个
    int blue = nums.size() - 1;  //蓝色部分的第一个下标，比blue大的部分是2
    int index = 0;               //循环下标
    //循环到蓝色部分的前一个
    while (index < blue + 1) {
      if (nums[index] == 0) {
        //如果遇到0，与红色部分的最后一个交换，red下标后移
        std::swap(nums[red++], nums[index++]);
      } else if (nums[index] == 2) {
        //遇到2，蓝色，与蓝色部分第一个交换，blue前移
        std::swap(nums[blue--], nums[index]);
      } else {
        index++;
      }
    }
  }
};
/*
法三
使用C++11的划分 partition
相当硬核
重排数组
先是按照是否=0，划分数组，返回不等于0部分的起始迭代器
在对不等于0部分按是否等于1划分
 */
class Solutio_75_back_2 {
 public:
  void sortSolors(std::vector<int>& nums) {
    std::partition(std::partition(nums.begin(), nums.end(),
                                  std::bind1st(std::equal_to<int>(), 0)),
                   nums.end(), std::bind1st(std::equal_to<int>(), 1));
  }
};
#endif