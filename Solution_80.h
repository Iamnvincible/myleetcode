#ifndef SOLUTION_80
#define SOLUTION_80
#include <iostream>
#include <vector>
class Solution_80
{
public:
  int removeDuplicates(std::vector<int> &nums)
  {
    int constraint = 2;
    int unique = constraint - 1, index = 0;
    for (index = constraint; index < nums.size(); index++)
    {
      if (nums[index] != nums[unique - constraint + 1])
      {
        unique += 1;
        nums[unique] = nums[index];
      }
    }
    if (nums.size() <= constraint)
    {
      return nums.size();
    }
    return unique + 1;
  }
  void test()
  {
    std::vector<int> nums = {};
    auto res = removeDuplicates(nums);
    std::cout << res << std::endl;
  }
};
#endif