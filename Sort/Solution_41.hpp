#ifndef SOLUTION_41
#define SOLUTION_41
/*
Given an unsorted integer array,
find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
给出一个整数数组，找出其中缺少的最小的正整数
不需要考虑0和负数
数组中元素可能有重复
 */
#include <algorithm>
#include <vector>
/*
O(nlogn)的办法是先排序，再比值
遇到重复的元素则跳过
直到找到整数大于构造的自增整数
 */
class Solution_41 {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    int i = 0;
    int size = nums.size();
    //排序
    std::sort(nums.begin(), nums.end());
    //跳过非正整数
    while (i < size && nums[i] <= 0) {
      i++;
    }
    //构造自增正整数
    int j = 1;
    while (i < size) {
      // j和数字相等
      if (j == nums[i]) {
        j++;
        i++;
      }
      // nums是中有重复的，会使j较大，此时j不必自增
      else if (j > nums[i]) {
        i++;
      }
      // j<nums[i]时找到最小的整数，跳出循环
      else {
        break;
      }
    }
    return j;
  }
};
class Solution_41_back {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    bucket_sort(nums);
    //遍历‘排序’后的数组，发现第一个不等于下标+1的元素结束
    //返回这个位置的下标+1
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != (i + 1)) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
  void test() {
    std::vector<int> v = {3, 4, -1, 1};
    int x = firstMissingPositive(v);
  }

 private:
  void bucket_sort(std::vector<int>& A) {
    const int n = A.size();
    for (int i = 0; i < n; i++) {
      while (A[i] != i + 1) {
        //如果数字<=0或比n大或与A[A[i]-1]相等就跳出循环
        // 跳过数值是 非正整数 || 数字超过数组长度 || 不需要交换
        if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1]) break;
        //否则交换A[i]和A[A[i]-1]
        //把不符合升序的元素和它这个数字应当在的位置的元素交换
        //因为目标是非零自然数的升序
        //比如数字2应当在下标为1的位置
        // A[i]是2，A[2-1]就是2这个数字应当在的位置，与这个位置的元素交换
        //如果交换后还是A[i]!=i+1，会继续循环
        //注意while循环中一直在操作同一个位置的元素
        std::swap(A[i], A[A[i] - 1]);
      }
    }
  }
};

#endif