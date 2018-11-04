#ifndef SOLUTION_26
#define SOLUTION_26
#include <iostream>
#include <vector>
class Solution_26
{
public:
  int removeDuplicates(std::vector<int> &nums)
  {
    int unique = 0, index = 0;
    for (index = 1; index < nums.size(); index++)
    {
      if (nums[index] != nums[unique])
      {
        unique += 1;
        nums[unique] = nums[index];
      }
    }
    if (nums.size() == 0)
    {
      return 0;
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