/*
 * @Author: Jie Lin
 * @Date: 2021-04-14 21:41:39
 * @LastEditTime: 2021-04-17 21:03:43
 * @LastEditors: Jie Lin
 * @Description:Solution 90
 * @FilePath: \myleetcode\Enum\Solution_90.hpp
 *
 */
#ifndef SOLUTION_90
#define SOLUTION_90
#include <algorithm>
#include <unordered_map>
#include <vector>
/**
 * @brief
 * @note   与78类似，但给出的数组中有重复元素
 */

//追加集合法，记录每个元素出现的次数
class Solution_90 {
 public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::unordered_map<int, int> stat;
    std::vector<std::vector<int>> res;
    std::vector<int> unique;
    for (auto item : nums) {
      if (stat.find(item) == stat.end()) {
        stat[item] = 1;
        unique.push_back(item);
      } else {
        stat[item]++;
      }
    }
    res.push_back({});
    for (auto item : unique) {
      int size = res.size();
      for (size_t i = 0; i < stat[item]; i++) {
        for (size_t j = 0; j < size; j++) {
          res.push_back(res[j]);
          res.back().insert(res.back().end(), i + 1, item);
        }
      }
    }
    return res;
  }
};
//排序后，记录上一个元素
class Solution_90_2 {
 public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::vector<std::vector<int>> res(1);
    std::sort(nums.begin(), nums.end());
    int pre = nums[0];
    int count = 1;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] != pre) {
        pre = nums[i];
        count = res.size();
      }
      int offset = res.size();
      // offset - count
      //是现在的长度-原有长度=上一个不相同数字之后，与当前数字相同数字增加的集合个数
      //这个个数就是一次相同数字会增加的元素个数，因为一个相同数字能增加的集合数量是相同的
      //当成下标来看，就可以作为上一个相同数字增加的集合前的位置
      for (size_t j = offset - count; j < offset; j++) {
        res.push_back(res[j]);
        res.back().push_back(nums[i]);
      }
    }

    return res;
  }
};
//递归
class Solution_90_3 {
 public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
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
      //在右边跳过重复的元素
      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        ++i;
      }
    }
  }
};
#endif