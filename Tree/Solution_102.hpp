#ifndef SOLUTION_102
#define SOLUTION_102
#include <queue>
#include <vector>
#include "TreeNode.h"
//二叉树层序遍历
class Solution_102 {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> res;
    std::queue<TreeNode *> levelnode;
    if (root) {
      levelnode.push(root);
    }
    while (levelnode.size() > 0) {
      res.push_back(level(levelnode));
    }
    return res;
  }

 private:
  std::vector<int> level(std::queue<TreeNode *> &levelnode) {
    std::vector<int> level;
    TreeNode *node = NULL;
    int size = levelnode.size();
    while (size--) {
      node = levelnode.front();
      level.push_back(node->val);
      if (node->left) {
        levelnode.push(node->left);
      }
      if (node->right) {
        levelnode.push(node->right);
      }
      levelnode.pop();
    }
    return level;
  }
};
//递归求解
//设定一个深度
//先深度后广度
class Solution_102_back {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> res;
    traverse(root, 1, res);
    return res;
  }

 private:
  void traverse(TreeNode *root, int level, std::vector<std::vector<int>> &res) {
    if (!root) {
      return;
    }
    if (level > res.size()) {
      res.push_back(std::vector<int>());
    }
    res[level - 1].push_back(root->val);
    traverse(root->left, level + 1, res);
    traverse(root->right, level + 1, res);
  }
};
#endif