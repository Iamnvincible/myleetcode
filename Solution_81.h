#ifndef SOLUTION_81
#define SOLUTION_81
#include <iostream>
#include <vector>
class Solution_81
{
  public:
    bool search(std::vector<int> &nums, int target)
    {
        int former = 0;
        int later = nums.size() - 1;
        while (former <= later)
        {
            int mid = (former + later) / 2;
            if (nums[mid] == target)
            {
                return true;
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
                return true;
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
        return false;
    }
};
class Sulotion_81_bak
{
  public:
    bool search(std::vector<int> &nums, int target)
    {
        int former = 0;
        int later = nums.size() - 1;
        while (former <= later)
        {
            int mid = (former + later) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[mid] > nums[former])
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
            else if (nums[mid] == nums[former])
            {
                former += 1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[later])
                {
                    former = mid + 1;
                }
                else
                {
                    later = mid - 1;
                }
            }
        }
        return false;
    }
};
#endif