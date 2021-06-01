/*
 * @Author: Jie Lin
 * @Date: 2021-06-01 23:30:05
 * @LastEditTime: 2021-06-01 23:32:25
 * @LastEditors: Jie Lin
 * @Description:Sum Root to Leaf Numbers
 * @FilePath: \myleetcode\Tree\Solution_129.hpp
 *
 */
#ifndef SOLUTION_129
#define SOLUTION_129
#include "TreeNode.h"
/**
 * @brief  计算树从跟节点到所有叶子节点组成的数字的和
 * @note
 * @retval None
 */
class Solution_129 {
 public:
  int sumNumbers(TreeNode* root) {
    int res = 0;
    getnum(root, 0, res);
    return res;
  }

 private:
  void getnum(TreeNode* root, int parent, int& res) {
    if (!root->left && !root->right) {
      parent = parent * 10 + root->val;
      res += parent;
      return;
    }
    if (root->left) {
      getnum(root->left, parent * 10 + root->val, res);
    }
    if (root->right) {
      getnum(root->right, parent * 10 + root->val, res);
    }
  }
};
#endif