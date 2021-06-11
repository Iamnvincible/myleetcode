/*
 * @Author: Jie Lin
 * @Date: 2021-06-11 23:40:28
 * @LastEditTime: 2021-06-12 00:18:33
 * @LastEditors: Jie Lin
 * @Description:Combination Sum
 * @FilePath: \myleetcode\ToBDecided\Solution_39.hpp
 *
 */
#ifndef SOLUTION_39
#define SOLUTION_39
#include <vector>
/**
 * @brief
 * 给出一个元素唯一的正整数数组和一个目标数，求出使用数组中若干数字（可重复使用同一个数字）组成和为目标数所有组合
 * @note
 * @retval None
 */
class Solution_39 {
 public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates,
                                               int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> toBeDecided;
    search(candidates, target, toBeDecided, res, 0);
    return res;
  }

 private:
  void search(std::vector<int>& candidates, int target, std::vector<int> tbd,
              std::vector<std::vector<int>>& res, int index) {
    if (target < 0)
      return;
    else if (target == 0) {
      res.push_back(tbd);
      return;
    } else {
      for (int i = index; i < candidates.size(); i++) {
        tbd.push_back(candidates[i]);
        search(candidates, target - candidates[i], tbd, res, i);
        //下一次递归前移除上一次添加的数字以寻找下一种可能组合
        tbd.pop_back();
      }
    }
  }
};
#endif
