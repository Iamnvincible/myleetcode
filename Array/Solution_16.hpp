#ifndef SOLOTION_16
#define SOLOTION_16
/*
 *Given an array nums of n integers and an integer target,
 *find three integers in nums such that the sum is closest to target.
 *Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *先排序，再用一层循环遍历到每个元素
 *第二层循环来左右夹逼
 *同时判断和与target的大小关系，准确进行夹逼
 *记录最小偏差以及最小偏差对于的三数之和，要求返回的是和而不是最小偏差
*/
#include <vector>
#include <algorithm>
class Solution_16
{
  public:
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        int closest = 0;
        int mingap = INT_MAX;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                {
                    return target;
                }
                else if (sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
                int gap = std::abs(sum - target);
                if (gap < mingap)
                {
                    mingap = gap;
                    closest = sum;
                }
            }
        }
        return closest;
    }
};
#endif