/*
 * @Author: Jie Lin
 * @Date: 2021-04-18 17:58:40
 * @LastEditTime: 2021-04-19 21:30:31
 * @LastEditors: Jie Lin
 * @Description:Solution 47
 * @FilePath: \myleetcode\Enum\Solution_47.hpp
 *
 */
#ifndef SOLUTION_47
#define SOLUTION_47
#include <unordered_map>
#include <vector>
class Solution_47 {
 public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> fix(nums.size(), -11);
    std::unordered_map<int, std::vector<int>> occ;
    std::unordered_map<int, int> count;
    for (auto&& i : nums) {
      if (count.find(i) == count.end()) {
        count[i] = 1;
      } else {
        count[i]++;
      }
    }

    get_permute(fix, nums, count, occ, res);
    return res;
  }

 private:
  void get_permute(std::vector<int> fix, std::vector<int>& nums,
                   std::unordered_map<int, int>& count,
                   std::unordered_map<int, std::vector<int>> occ,
                   std::vector<std::vector<int>>& res) {
    int target_num = -11;
    bool found = false;
    for (size_t i = 0; i < nums.size() && !found; i++) {
      if (count_occ(nums[i], fix) < count[nums[i]]) {
        target_num = nums[i];
        found = true;
      }
    }

    if (!found) {
      res.push_back(fix);
    } else {
      for (size_t i = 0; i < fix.size(); i++) {
        if (fix[i] == -11 && !contain(i, occ[target_num])) {
          fix[i] = target_num;
          occ[target_num].push_back(i);
          get_permute(fix, nums, count, occ, res);
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
  int count_occ(int target, std::vector<int>& nums) {
    int count = 0;
    for (auto&& i : nums) {
      if (i == target) {
        count++;
      }
    }
    return count;
  }
};

#endif