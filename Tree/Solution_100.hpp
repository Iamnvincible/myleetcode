#ifndef SOLUTION_100
#define SOLUTION_100
/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and
the nodes have the same value.

给出两棵树，判断数是否相同
相同指的是树结构和对应节点值均一致
通过遍历两棵树判断结构和值即可
 */
#include "TreeNode.h"
class Solution_100 {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    //两边都是空指针，认为一致
    if (p == q) {
      return true;
    }
    //两边都不是空指针，判断节点值
    else if (p && q) {
      //在节点值一致的前提下，先序遍历
      if (p->val == q->val) {
        //递归遍历左子树
        bool left = isSameTree(p->left, q->left);
        //左边返回false直接退出
        if (!left) return false;
        //递归遍历右子树，并返回值
        bool right = isSameTree(p->right, q->right);
        return right;
      }
      //节点值不一致返回false
      else {
        return false;
      }
    }
    //有一边是空指针，返回false
    else {
      return false;
    }
  }
};
#endif