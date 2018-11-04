#ifndef SOLUTION_31
#define SOLUTION_31
/*
 *Implement next permutation,
 *which rearranges numbers into the lexicographically next greater permutation of numbers.
 *If such arrangement is not possible,
 *it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *The replacement must be in-place and use only constant extra memory.
 *Here are some examples.
 *Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *1,2,3 → 1,3,2
 *3,2,1 → 1,2,3
 *1,1,5 → 1,5,1
 *给出列数，求这列数的下一个排列数
 *什么是下一个排列数？
 *一列数（长度为n）本身是可以得到它的n!种排列，
 *这n！种排列中按照【从首位到末位，首位数越小越优先；后一位按照相同的规则，依次排序】的规则可以对他们进行排序
 *规则相当于是把排列好的数列当成一个个数字，把这些数字从小到大排序
 *那么给出一个数列求出它的下一个数（比它大的最小的数）
 *如果给出的数列代表了最大的数（即已经是降序）那么给出最小的数
 *方法
 *从后往前，找第一个不满足从后往前是升序的数（单个数认为是满足升序）
 *在这个数之后的数字中找一个比它大且最小的数与之交换
 *再对这个数之后的数升序排序
*/
#include <vector>
#include <algorithm>
#include <iostream>
class Solution_31
{
  public:
    void nextPermutation(std::vector<int> &nums)
    {
        int size = nums.size();
        if (size <= 1)
            return;
        int cur, pre = 0;
        for (int i = size - 1; i - 1 >= 0; i--)
        {
            cur = nums[i];
            pre = nums[i - 1];
            if (cur <= pre)
            {
                continue;
            }
            //找一个比pre大的最小元素
            for (int j = size - 1; j >= i; j--)
            {
                if (pre >= nums[j])
                {
                    continue;
                }
                //交换时要用下标交换（引用）
                int temp = nums[j];
                nums[j] = pre;
                nums[i - 1] = temp;
                std::sort(nums.begin() + i, nums.end());
                return;
            }
        }
        std::sort(nums.begin(), nums.end());
    }
    void test()
    {
        std::vector<int> nums = {1,7,5,4,3,1,2,8,6};
        nextPermutation(nums);
        for (auto i : nums)
        {
            std::cout << i << " ";
        }
    }
};
#endif