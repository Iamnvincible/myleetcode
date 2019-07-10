#ifndef SOLUTION_107
#define SOLUTION_107
#include <algorithm>
#include <queue>
#include <vector>
//二叉树层序遍历2,是102题的倒序，即从二叉树底部往根
//将102的结果逆序一下即可
//节点结构体
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_107 {
 public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
    std::vector<std::vector<int>> res;
    std::queue<TreeNode *> q;
    if (root) {
      q.push(root);
    }
    while (q.size() > 0) {
      //从vector的头部插入新节点
      auto begit = res.begin();
      res.insert(begit, level(q));
    }
    //或结束后转置
    // std::reverse(res.begin(), res.end());
    return res;
  }

 private:
  std::vector<int> level(std::queue<TreeNode *> &q) {
    std::vector<int> res;
    int size = q.size();
    while (size--) {
      auto node = q.front();
      res.push_back(node->val);
      q.pop();
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
    return res;
  }
};
//递归
class Solution_107_back {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> res;
    traverse(root, 1, res);
    std::reverse(res.begin(), res.end());
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