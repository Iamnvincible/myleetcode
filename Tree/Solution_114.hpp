#ifndef SOLUTION_114
#define SOLUTION_114
/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:
    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

把二叉树转换成链表，只用右指针
 */
#include <iostream>
#include <stack>
#include "TreeNode.h"
//递归实现
class Solution_114 {
 public:
  void flatten(TreeNode* root) {
    // root非空时执行
    if (root) {
      TreeNode* right = root->right;  //记录左子树指针
      TreeNode* left = root->left;    //记录右子树指针
      //在左子树非空的情况下，对左子树做展平操作
      if (left) {
        flatten(left);
      }
      //操作完成后，root的左边置空，root的右子树为展平后的左子树
      root->left = nullptr;
      root->right = left;

      //左子树操作完成后对右子树进行展平操作
      //首先需要找到左子树展平后的最后一个节点
      //右子树接在这个节点后面
      //最后对右子树进行展平操作
      while (root->right) {
        //遍历到左侧分支尾部
        root = root->right;
      }
      root->right = right;
      flatten(right);
    }
  }
};
//非递归实现(错误范例)
//代码太长，没有通用性，为了新的情况增加新的代码，冗余而难以维护
class Solution_114_back {
 public:
  void flatten(TreeNode* root) {
    std::stack<TreeNode*> s;
    if (root) {
      s.push(root);
      std::cout << root->val << " ";
    }
    while (s.size()) {
      auto node = s.top();
      if (node->left) {
        s.push(node->left);
        std::cout << node->left->val << " ";
      } else {
        s.pop();
        if (s.size() == 0) {
          if (node->right) {
            s.push(node->right);
            std::cout << node->right->val << "/";
            continue;
          } else {
            break;
          }
        }
        auto parent = s.top();       //取栈顶元素，其为node的父节点
        parent->left = nullptr;      //断其左子树
        auto right = parent->right;  //记录右子树
        //如果节点与右子树不同，将节点附到父节点右子树
        if (node != parent->right) {
          parent->right = node;
          //将节点移动到右子树非空且左子树为空的节点
          //这个节点为排好序的最下层节点
          while (node->right && !node->left) {
            s.push(node);
            node = node->right;
          }
          //优先对左子树排序（先序）
          if (node->left) {
            s.push(node);
            std::cout << node->val << " ";
            s.push(node->left);
            std::cout << node->left->val << " ";
            if (right) node->right = right;
          } else if (right) {
            //需要更多代码来完成，放弃
            node->right = right;
            s.push(node);
            std::cout << node->val << " ";
            s.push(node->right);
            std::cout << node->right->val << " ";
          }
        } else {
          s.pop();
        }
      }
    }
  }
};
//非递归实现
//用栈实现，栈非空时，先出栈，再把左右子树入栈
//左子树置空，右子树为栈顶节点
//太巧妙了
class Solution_114_back_2 {
 public:
  void flatten(TreeNode* root) {
    std::stack<TreeNode*> s;
    if (root) {
      s.push(root);
    }
    while (!s.empty()) {
      auto p = s.top();
      s.pop();
      if (p->right) {
        s.push(p->right);
      }
      if (p->left) {
        s.push(p->left);
      }
      p->left = nullptr;
      if (!s.empty()) {
        p->right = s.top();
      }
    }
  }
};
#endif