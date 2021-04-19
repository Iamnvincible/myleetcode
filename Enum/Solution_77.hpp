/*
 * @Author: Jie Lin
 * @Date: 2021-04-19 21:30:48
 * @LastEditTime: 2021-04-20 00:49:34
 * @LastEditors: Jie Lin
 * @Description:Combinations
 * @FilePath: \myleetcode\Enum\Solution_77.hpp
 *
 */
#ifndef SOLUTION_77
#define SOLUTION_77
//组合C(n,k)
#include <vector>
class Solution_77 {
 public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> nums;
    std::vector<int> fix;
    for (int i = 0; i < n; i++) {
      nums.push_back(i + 1);
    }
    get_combinations(nums, k, 0, fix, res);
    return res;
  }

 private:
  /**
   * @brief
   * @note  固定fix.size()个数，从nums里取k个数字的所有组合
   * @param  &nums: 全部数字的引用，升序
   * @param  k: 取几个数组合
   * @param  index: 从数组第几个数开始取
   * @param  fix: 已经确定的组合数
   * @param  &res: 返回值的引用
   * @retval None
   */
  void get_combinations(std::vector<int> &nums, int k, int index,
                        std::vector<int> fix,
                        std::vector<std::vector<int>> &res) {
    if (k == 0) {
      res.push_back(fix);
      return;
    }
    //从位置index取起，取k个数
    for (size_t i = index; i <= nums.size() - k; i++) {
      //依次取数
      fix.push_back(nums[i]);
      //递归，固定了fix.size()个数字，还可以取k-1个数
      get_combinations(nums, k - 1, i + 1, fix, res);
      //弹出，让位下一个数，取数时从小到大取
      fix.pop_back();
    }
  }
};
#endif
