/*
 * @Author: Jie Lin
 * @Date: 2021-04-17 21:07:35
 * @LastEditTime: 2021-04-18 17:59:07
 * @LastEditors: Jie Lin
 * @Description:Solution 46
 * @FilePath: \myleetcode\Enum\Solution_46.hpp
 *
 */
#ifndef SOLUTION_46
#define SOLUTION_46
/**
 * @brief
 * @note   求全排列
 * @retval None
 */
#include <vector>
class Solution_46 {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> fix(nums.size(), -11);
    get_permute(fix, nums, res);
    return res;
  }

 private:
  void get_permute(std::vector<int> fix, std::vector<int>& nums,
                   std::vector<std::vector<int>>& res) {
    int target_num = -11;
    bool found = false;
    for (size_t i = 0; i < nums.size() && !found; i++) {
      // nums[i]不在fix中
      if (!contain(nums[i], fix)) {
        target_num = nums[i];
        found = true;
      }
    }

    if (!found) {
      res.push_back(fix);
    } else {
      for (size_t i = 0; i < fix.size(); i++) {
        if (fix[i] == -11) {
          fix[i] = target_num;
          get_permute(fix, nums, res);
          fix[i] = -11;
        }
      }
    }
  }
  bool contain(int target, std::vector<int>& nums) {
    for (auto&& i : nums) {
      if (i == target) {
        return true;
      }
    }
    return false;
  }
};
#endif