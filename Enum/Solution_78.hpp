/*
 * @Author: Jie Lin
 * @Date: 2021-04-11 12:00:44
 * @LastEditTime: 2021-04-17 21:00:13
 * @LastEditors: Jie Lin
 * @Description:Solution 78
 * @FilePath: \myleetcode\Enum\Solution_78.hpp
 *
 */
#ifndef SOLLUTION_78
#define SOLLUTION_78
/**
 *求集合的子集，集合数量为n，子集数量为2^n
 *
 *
 */
#include <vector>
//非递归
class Solution_78 {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    res.push_back({});
    for (size_t i = 0; i < nums.size(); i++) {
      int s = res.size();
      for (size_t j = 0; j < s; j++) {
        res.push_back(res[j]);
        res.back().push_back(nums[i]);
      }
    }
    return res;
  }
};
//递归
class Solution_78_2 {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> out;
    getSubsets(nums, 0, out, res);
    return res;
  }

 private:
  void getSubsets(std::vector<int>& nums, int pos, std::vector<int>& out,
                  std::vector<std::vector<int>>& res) {
    res.push_back(out);
    for (size_t i = pos; i < nums.size(); i++) {
      out.push_back(nums[i]);
      getSubsets(nums, i + 1, out, res);
      out.pop_back();
    }
  }
};
//位运算
class Solution_78_3 {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    int size = nums.size();
    int amount = 1 << size;
    for (size_t i = 0; i < amount; i++) {
      std::vector<int> item;
      for (size_t j = i, k = 0; j > 0; j >>= 1, k++) {
        if (j & 1) {
          item.push_back(nums[k]);
        }
      }
      res.push_back(item);
    }
    return res;
  }
};
#endif