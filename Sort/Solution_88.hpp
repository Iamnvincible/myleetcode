#ifndef SOLUTION_88
#define SOLUTION_88
/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one
sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m +
n) to hold additional elements from nums2.

将两个有序数组合并
一个数组有足够空间，合并到这个数组中

不需要额外空间的办法就是从长数组后面开始合并
注意结束条件
长数组合并完了，短数组还没完的时候，短数组剩下的并入长数组剩下的位置
否则，短数组合并完了，因为数组本来就有序，不需要对长数组剩下的再操作了
再用一个三元运算符？，代码非常简洁
 */
#include <vector>
class Solution_88 {
 public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int size = m + n - 1;
    while (m * n) {
      nums1[size--] = nums1[m - 1] >= nums2[n - 1] ? nums1[--m] : nums2[--n];
    }
    while (n > 0) {
      nums1[size--] = nums2[--n];
    }
  }
};
#endif