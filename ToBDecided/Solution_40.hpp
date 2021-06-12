/*
 * @Author: Jie Lin
 * @Date: 2021-06-12 21:27:00
 * @LastEditTime: 2021-06-12 22:11:50
 * @LastEditors: Jie Lin
 * @Description:Combination Sum II
 * @FilePath: \myleetcode\ToBDecided\Solution_40.hpp
 *
 */
#ifndef SOLUTION_40
#define SOLUTION_40
#include <algorithm>
#include <vector>
/**
 * @brief
 * 类似39题，不同的是，给出的数组中有重复元素，所以每个数组中的元素只能用一次
 * 先排序，用完一个数后，跳过与之相同的数
 * @note
 * @retval None
 */
class Solution_40 {
 public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates,
                                                int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> res;
    std::vector<int> toBeDecided;

    search(candidates, target, toBeDecided, res, 0);
    return res;
  }

 private:
  void search(std::vector<int>& candidates, int target, std::vector<int> tbd,
              std::vector<std::vector<int>>& res, int index) {
    if (target < 0) {
      return;
    } else if (target == 0) {
      res.push_back(tbd);
    } else {
      for (int i = index; i < candidates.size(); i++) {
        tbd.push_back(candidates[i]);
        search(candidates, target - candidates[i], tbd, res, i + 1);
        tbd.pop_back();
        //跳过重复元素
        for (int j = i; j < candidates.size(); j++) {
          if (candidates[j] != candidates[i]) {
            i = j - 1;
            break;
          }
          //如果到结尾都是重复元素，外面大循环也可以结束
          if (j == candidates.size() - 1) {
            i = j;
          }
        }
      }
    }
  }
};
#endif