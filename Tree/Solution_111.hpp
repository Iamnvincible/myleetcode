/*
 * @Author: Jie Lin
 * @Date: 2021-06-18 21:21:08
 * @LastEditTime: 2021-06-18 21:27:44
 * @LastEditors: Jie Lin
 * @Description:Minimum Depth of Binary Tree
 * @FilePath: \myleetcode\Tree\Solution_111.hpp
 *
 */
#ifndef SOLUTION_111
#define SOLUTION_111
#include <climits>

#include "TreeNode.h"
/**
 * @brief  求二叉树的最小深度，这里的最小深度指的是
 * 从根节点到最近的 叶子 节点的层数
 * @note
 * @retval None
 */
class Solution_111 {
 public:
  int minDepth(TreeNode* root) {
    int res = traverse(root, 0);
    return res;
  }

 private:
  int traverse(TreeNode* root, int depth) {
    if (root == nullptr) {
      return depth;
    } else if (root->left == nullptr && root->right == nullptr) {
      //只有遇到叶子节点深度才+1
      return depth + 1;
    } else {
      //由于遇到一边没有子树的节点不是叶子节点，不能算作较小的深度
      //所以遇到一边没有子树的节点，将没有子树节点深度置为最大值
      int left = INT_MAX;
      int right = INT_MAX;
      if (root->left != nullptr) {
        left = traverse(root->left, depth + 1);
      }
      if (root->right != nullptr) {
        right = traverse(root->right, depth + 1);
      }
      return left < right ? left : right;
    }
  }
};
#endif
