#ifndef SOLUTION_33
#define SOLUTION_33
#include <iostream>
#include <vector>
class Solution_33
{
  public:
    int search(std::vector<int> &nums, int target)
    {
        int former = 0;
        int later = nums.size() - 1;
        while (former <= later)
        {
            int mid = (former + later) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] >= nums[former])
            {
                if (target >= nums[former] && target < nums[mid])
                {
                    later = mid - 1;
                }
                else
                {
                    former = mid + 1;
                }
            }
            else
            {
                if (target <= nums[later] && target > nums[mid])
                {
                    former = mid + 1;
                }
                else
                {
                    later = mid - 1;
                }
            }
        }
        return -1;
    }
    void test()
    {
        std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        auto res = search(nums, target);
        std::cout << res << std::endl;
    }
};

class Solution_33_bak
{
  public:
    int search(std::vector<int> &nums, int target)
    {
        int former = 0;
        int later = nums.size() - 1;
        while (former <= later)
        {
            int mid = (former + later) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (target > nums[former])
            {
                if (target < nums[mid] && target > nums[later] &&
                    nums[mid] > nums[former] && nums[mid] > nums[later])
                {
                    later = mid - 1;
                }
                else if (target > nums[mid] && target > nums[later] &&
                         nums[mid] < nums[former] && nums[mid] < nums[later])
                {
                    later = mid - 1;
                }
                else if (target < nums[mid] && nums[mid] > nums[former] &&
                         nums[mid] < nums[later] && target < nums[later])
                {
                    later = mid - 1;
                }
                else
                {
                    former = mid + 1;
                }
            }
            else if (target == nums[former])
            {
                return former;
            }
            else
            {
                if (target <= nums[later] && nums[former] >= nums[mid] &&
                    target > nums[mid] && nums[mid] < nums[later])
                {
                    former = mid + 1;
                }
                else if (target <= nums[later] && nums[former] <= nums[mid] &&
                         target < nums[mid] && nums[mid] > nums[later])
                {
                    former = mid + 1;
                }
                else
                {
                    later = mid - 1;
                }
            }
        }
        return -1;
    }
};
#endif