#ifndef SOLUTION_27
#define SOLUTION_27
/*
 *Given an array nums and a value val,
 *remove all instances of that value in-place and return the new length.
 *Do not allocate extra space for another array,
 *you must do this by modifying the input array in-place with O(1) extra memory.
 *The order of elements can be changed.
 *It doesn't matter what you leave beyond the new length.
 *对原数组操作，在返回值下标内只留下不是目标值的元素
 *一种方法从后往前找，从末尾元素开始和前面遍历的目标元素替换
 *一种方法从前往后找，遇到不是目标元素的留下
*/
#include <vector>
class Solution_27
{
  public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int rm = 0;
        int len = nums.size();
        for (int i = len - 1; i >= 0; i--)
        {
            if (nums[i] == val)
            {
                rm++;
                nums[i] = nums[len - rm];
            }
        }
        return len - rm;
    }
};
class Solution_27_bak
{
  public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};
#endif