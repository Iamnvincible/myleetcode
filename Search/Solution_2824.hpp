
#ifndef SOLUTION_2824
#define SOLUTION_2824
#include <algorithm>
#include <vector>
/*
2824. Count Pairs Whose Sum is Less than Target
Given a 0-indexed integer array nums of length n and an integer target,
return the number of pairs (i, j) 
where 0 <= i < j < n and 
nums[i] + nums[j] < target.

sort the array at first.
calculate the sum of left and right position.

*/
class Solution_2824 {
public:
  int countPairs(std::vector<int> &nums, int target) {
    int result = 0;
    std::sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      if (nums[left] + nums[right] < target) {
        result += (right - left);
        left++;
      } else {
        right--;
      }
    }
    return result;
  }
};
#endif