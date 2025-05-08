#ifndef SOLOTION_16
#define SOLOTION_16
/*
 *Given an array nums of n integers and an integer target,
 *find three integers in nums such that the sum is closest to target.
 *Return the sum of the three integers. You may assume that each input would
 *have exactly one solution. 先排序，再用一层循环遍历到每个元素
 *第二层循环来左右夹逼
 *同时判断和与target的大小关系，准确进行夹逼
 *记录最小偏差以及最小偏差对于的三数之和，要求返回的是和而不是最小偏差
 */
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
class Solution_16 {
public:
  int threeSumClosest(std::vector<int> &nums, int target) {
    int closest = 0;
    int mingap = INT_MAX;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == target) {
          return target;
        } else if (sum < target) {
          j++;
        } else {
          k--;
        }
        int gap = std::abs(sum - target);
        if (gap < mingap) {
          mingap = gap;
          closest = sum;
        }
      }
    }
    return closest;
  }
};
class Solution_16_1 {
public:
  int threeSumClosest(std::vector<int> &nums, int target) {
    int result = INT_MAX;
    int min_diff = INT_MAX;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      int x = nums[i];
      int j = i + 1;
      int k = nums.size() - 1;
      // skip duplicate values
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int min_sum = x + nums[i + 1] + nums[i + 2];
      int max_sum = x + nums[k] + nums[k - 1];
      // if the minimal value is larger than target, other values must be larger
      // it's not necessary to run further loops
      if (min_sum > target) {
        if (min_sum - target < min_diff) {
          result = min_sum;
        }
        break;
      }
      // if the maximal value is letter than target, the j,k loop must get sum
      // less than that. it's not necessary to run the following j,k loop. but
      // the i loop is still necessary, becase increment of i may lead to larger
      // sum.
      if (max_sum < target) {
        if (target - max_sum < min_diff) {
          result = max_sum;
          min_diff = target - max_sum;
        }
        continue;
      }
      while (j < k) {
        int sum = x + nums[j] + nums[k];
        int diff = std::abs(target - sum);
        if (diff == 0)
          return target;
        else if (diff < min_diff) {
          result = sum;
          min_diff = diff;
        } else {
          if (sum > target) {
            k--;
            // skip duplicate values
            while (j < k && nums[k] == nums[k + 1]) {
              k--;
            }
          } else {
            j++;
            // skip duplicate values
            while (j < k && nums[j] == nums[j - 1]) {
              j++;
            }
          }
        }
      }
    }
    return result;
  }
};
#endif