#ifndef SOLUTION_101
#define SOLUTION_101
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric
around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
给出一棵树，判断节点是不是对称的
对称指的是关于中线的对称
要取得两边对应位置的节点比较值
所以拿到两个节点时首先要确保两个节点的值相等
下一步是比较左节点的左孩子值和右节点的右孩子值和
左节点的右孩子和右节点的左孩子值
这样才能保证“对称”
 */
#include <stack>
#include <vector>
#include "TreeNode.h"
//递归解法
//递归函数的两个节点指针作为参数
//比较时如果两个节点都为空返回true
//两个节点都非空的情况下，比较两个节点值，在递归调用比较方法
//两两端的比较结果相与，两端都对称树才对称
//有一个节点非空时返回false
class Solution_101 {
 public:
  bool isSymmetric(TreeNode* root) {
    if (root) {
      return compare(root->left, root->right);
    }
    return true;
  }

 private:
  bool compare(TreeNode* left, TreeNode* right) {
    if (left == right) {
      return true;
    } else if (left && right && left->val == right->val) {
      return compare(left->left, right->right) &&
             compare(right->left, left->right);
    } else {
      return false;
    }
  }
};
//非递归法
//使用一个栈记录节点指针
//出栈时，一对一对指针出栈
//比较两个节点的值，方法同上
//注意将孩子入栈时还是要保证能够两端比较
//即左-左与右-右||左-右与右-左
class Solution_101_back {
 public:
  bool isSymmetric(TreeNode* root) {
    std::stack<TreeNode*> s;
    if (root) {
      s.push(root->right);
      s.push(root->left);
    }
    while (!s.empty()) {
      auto node1 = s.top();
      s.pop();
      auto node2 = s.top();
      s.pop();
      if (node1 == node2) {
        continue;
      } else if (node1 && node2 && node1->val == node2->val) {
        s.push(node1->left);
        s.push(node2->right);
        s.push(node1->right);
        s.push(node2->left);
      } else {
        return false;
      }
    }
    return true;
  }
};
#endif