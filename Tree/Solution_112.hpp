/*
 * @Author: Jie Lin
 * @Date: 2021-05-22 22:20:21
 * @LastEditTime: 2021-05-22 22:24:51
 * @LastEditors: Jie Lin
 * @Description:Path Sum
 * @FilePath: \myleetcode\Tree\Solution_112.hpp
 *
 */
#ifndef SOLUTION_112
#define SOLUTION_112
#include "TreeNode.h"
/**
 * @brief  判断二叉树有没有一条从根节点到叶子节点的路径和等于给定值
 * @note
 * @retval None
 */
class Solution_112 {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    return recursive(root, 0, targetSum);
  }

 private:
  bool recursive(TreeNode* root, int tmp, int targetSum) {
    if (!root) {
      return false;
    } else if (!root->left && !root->right) {
      return (tmp + root->val) == targetSum;
    } else {
      /*
            if (root->left) {
              bool left = recursive(root->left, tmp + root->val, targetSum);
              if (!left) {
                bool right = recursive(root->right, tmp + root->val, targetSum);
                return right;
              }
            } else {
              bool right = recursive(root->right, tmp + root->val, targetSum);
              if (!right) {
                bool left = recursive(root->left, tmp + root->val, targetSum);
                return left;
              }
            }
            return true;
      */
      //上面的代码可以简化成下面一个或逻辑
      return recursive(root->left, tmp + root->val, targetSum) ||
             recursive(root->right, tmp + root->val, targetSum);
    }
  }
};
#endif