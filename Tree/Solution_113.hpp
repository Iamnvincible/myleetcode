/*
 * @Author: Jie Lin
 * @Date: 2021-06-13 21:19:28
 * @LastEditTime: 2021-06-13 21:52:39
 * @LastEditors: Jie Lin
 * @Description:Path Sum II
 * @FilePath: \myleetcode\Tree\Solution_113.hpp
 *
 */
#ifndef SOLUTION_113
#define SOLUTION_113
#include <vector>

#include "TreeNode.h"
/**
 * @brief 在112题的基础上，找出所有根到叶子节点权值和等于目标数的路径
 * @note
 * 递归找，因为到叶子节点才能算一条路径，节点值可正可负，所以遇到叶子节点判断是否满足条件
 * 满足则添加到结果集中；
 * 遇到非叶子节点，将节点值加入备选路径中，目标值减去节点值，分别尝试从左右子树向下找
 * @retval None
 */
class Solution_113 {
 public:
  std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
    std::vector<std::vector<int>> res;
    std::vector<int> toBeDecide;
    if (root) {
      search(root, targetSum, toBeDecide, res);
    }
    return res;
  }

 private:
  void search(TreeNode* root, int target, std::vector<int> tbd,
              std::vector<std::vector<int>>& res) {
    if (root->left == nullptr && root->right == nullptr) {
      if (target - root->val == 0) {
        tbd.push_back(root->val);
        res.push_back(tbd);
      }
      return;
    } else {
      int val = root->val;
      tbd.push_back(val);
      if (root->left) {
        search(root->left, target - val, tbd, res);
      }
      if (root->right) {
        search(root->right, target - val, tbd, res);
      }
    }
  }
};
#endif