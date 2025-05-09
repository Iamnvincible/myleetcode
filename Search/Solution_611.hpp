#ifndef SOLUTION_611
#define SOLUTION_611
#include <algorithm>
#include <vector>
/*
Given an integer array nums,
return the number of triplets chosen from the array
that can make triangles
if we take them as side lengths of a triangle.
*/
class Solution_611 {
public:
  int triangleNumber(std::vector<int> &nums) {
    int result = 0;
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size - 2; i++) {
      int x = nums[i];
      if (x == 0) {
        continue;
      }
      int j = i + 1;
      for (int k = i + 2; k < size; k++) {
        while (nums[k] - nums[j] >= x) {
          j++;
        }
        result += k - j;
      }
    }
    return result;
  }
};

class Solution_611_1 {
public:
  int triangleNumber(std::vector<int> &nums) {
    int result = 0;
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size - 2; i++) {
      int x = nums[i];
      if (x == 0) {
        continue;
      }
      int last_k = i + 2;
      for (int j = i + 1; j < size - 1; j++) {
        int k = last_k;
        int two_sides = x + nums[j];
        while (k < size && two_sides > nums[k]) {
          k++;
        }
        result += (k - j - 1);
        last_k = k - 1;
      }
    }
    return result;
  }
};
class Solution_611_2 {
public:
  int triangleNumber(std::vector<int> &nums) {
    int result = 0;
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int k = size - 1; k > 1; k--) {
      if (nums[0] + nums[1] > nums[k]) { // 优化一
        result += (k + 1) * k * (k - 1) / 6;
        break;
      }
      if (nums[k - 2] + nums[k - 1] <= nums[k]) { // 优化二
        continue;
      }
      int i = 0;
      int j = k - 1;
      while (i < j) {
        if (nums[i] + nums[j] > nums[k]) {
          result += (j - i);
          j--;
        } else {
          i++;
        }
      }
    }
    return result;
  }
};
#endif
// 2,2,3,4

// 2,3,4
// 2,3,4
// 2,2,3