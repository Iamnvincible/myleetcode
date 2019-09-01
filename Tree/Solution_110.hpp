#ifndef SOLUTION_110
#define SOLUTION_110
/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:
a binary tree in which the depth of the two subtrees of every node never
differ by more than 1.

判断一棵二叉树是不是平衡二叉树
*/
#include <algorithm>
#include <cstdlib>
#include "TreeNode.h"
class Solution_110 {
 public:
  bool isBalanced(TreeNode *root) {
    bool res = true;  //用一个变量记录遍历过程中是否有出现不平衡
    int dep = depth(root, res);
    return res;
  }
  int depth(TreeNode *root, bool &res) {
    if (!root) return 0;  //空指针深度为0
    //递归求得子树深度
    int left = !root->left ? 0 : depth(root->left, res) + 1;
    int right = !root->right ? 0 : depth(root->right, res) + 1;
    //判断子树深度差是否＞1
    if (abs(left - right) > 1) {
      res = false;
    }
    //返回较深的那一支子树深度
    return left > right ? left : right;
  }
};
class Solution_110_back {
 public:
  bool isBalanced(TreeNode *root) { return balancedHeight(root) >= 0; }

 private:
  int balancedHeight(TreeNode *root) {
    if (!root) return 0;
    int left = balancedHeight(root->left);
    int right = balancedHeight(root->right);
    //如果两边深度小于0,或者左右差大于1,返回-1
    // left|right小于0意味着有一边不平衡
    if (left < 0 || right < 0 || abs(left - right) > 1) {
      return -1;
    }
    //只有当两边不为负数且深度差不大于1时才返回深度+1
    return std::max(left, right) + 1;
  }
};
#endif