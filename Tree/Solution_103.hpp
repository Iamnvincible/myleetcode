#ifndef SOLUTION 103
#define SOLUTION 103
#include <algorithm>
#include <queue>
#include <vector>
//二叉树之字形遍历
//节点结构体
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution_103 {
 public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    //用一个标记记录是从左往右还是从右往左
    int lefttoright = 1;
    std::vector<std::vector<int>> res;
    std::queue<TreeNode *> q;
    if (root) {
      q.push(root);
    }
    while (q.size() > 0) {
      res.push_back(level(q, lefttoright));
      lefttoright ^= 1;
    }
    return res;
  }

 private:
  std::vector<int> level(std::queue<TreeNode *> &q, int left) {
    int size = q.size();
    std::vector<int> res;
    while (size--) {
      auto node = q.front();
      res.push_back(node->val);
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
      q.pop();
    }
    if (!left) {
      std::reverse(res.begin(), res.end());
    }
    return res;
  }
};
//递归
class Solution_103_back {
 public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
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
    //奇数偶数层添加的方向不一样
    if (level & 1) {
      res[level - 1].push_back(root->val);
    } else {
      res[level - 1].insert(res[level - 1].begin(), root->val);
    }

    traverse(root->left, level + 1, res);
    traverse(root->right, level + 1, res);
  }
};
#endif