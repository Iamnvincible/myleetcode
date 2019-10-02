#ifndef SOLUTION_95
#define SOLUTION_95
/*
Given an integer n, generate all structurally unique BST's (binary search trees)
that store values 1 ... n.
给出n个节点，返回所有可能的二叉查找树
 */
#include <vector>
#include "TreeNode.h"

//先算出所有可能的数量
// f数组表示了在若干个节点情况下可能的二叉搜索树个数
class Solution_95 {
 public:
  std::vector<TreeNode *> generateTrees(int n) {
    std::vector<TreeNode *> res;
    if (n == 0) {
      return res;
    }
    if (n == 1) {
      res.push_back(new TreeNode(1));
      return res;
    }
    std::vector<int> f(n + 1, 0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int k = 0; k < i; k++) {
        f[i] += f[k] * f[i - k - 1];
      }
    }
    //以i为根节点，构造二叉搜索树
    for (size_t i = 1; i <= n; i++) {
      std::vector<int> smaller;
      std::vector<int> bigger;
      for (size_t j = 1; j <= n; j++) {
        if (j < i) {
          smaller.push_back(j);
        } else if (j > i) {
          bigger.push_back(j);
        }
      }
      auto nodes = generate(i, smaller, bigger, f);
      res.insert(res.end(), nodes.begin(), nodes.end());
    }

    return res;
  }

 private:
  //以i为根节点，smaller表示i的左子树节点，bigger表示右子树节点
  //这里smaller 和bigger不需要是连续的数字更加通用
  std::vector<TreeNode *> generate(int i, std::vector<int> smaller,
                                   std::vector<int> bigger,
                                   std::vector<int> f) {
    //求得在特定数量节点时，二叉搜索树的数量
    std::vector<TreeNode *> res(f[smaller.size()] * f[bigger.size()]);
    for (size_t j = 0; j < res.size(); j++) {
      res[j] = new TreeNode(i);
    }
    //生成左右子树
    std::vector<TreeNode *> left;
    for (size_t j = 0; j < smaller.size(); j++) {
      std::vector<int> small;
      std::vector<int> big;
      for (size_t k = 0; k < smaller.size(); k++) {
        if (smaller[k] < smaller[j]) {
          small.push_back(smaller[k]);
        } else if (smaller[k] > smaller[j]) {
          big.push_back(smaller[k]);
        }
      }
      auto g = generate(smaller[j], small, big, f);
      left.insert(left.end(), g.begin(), g.end());
    }
    std::vector<TreeNode *> right;
    for (size_t j = 0; j < bigger.size(); j++) {
      std::vector<int> small;
      std::vector<int> big;
      for (size_t k = 0; k < bigger.size(); k++) {
        if (bigger[k] < bigger[j]) {
          small.push_back(bigger[k]);
        } else if (bigger[k] > bigger[j]) {
          big.push_back(bigger[k]);
        }
      }
      auto g = generate(bigger[j], small, big, f);
      right.insert(right.end(), g.begin(), g.end());
    }
    //拼接
    int index = 0;
    if (left.size() == 0) {
      for (size_t k = 0; k < right.size(); k++) {
        auto append = res[index++];
        append->right = right[k];
      }
      return res;
    }
    if (right.size() == 0) {
      for (size_t j = 0; j < left.size(); j++) {
        auto append = res[index++];
        append->left = left[j];
      }
      return res;
    }
    for (size_t j = 0; j < left.size(); j++) {
      for (size_t k = 0; k < right.size(); k++) {
        auto append = res[index++];
        append->left = left[j];
        append->right = right[k];
      }
    }

    return res;
  }
};
class Solution_95_back {
 public:
  std::vector<TreeNode *> generateTrees(int n) {
    std::vector<TreeNode *> res;
    if (n == 0) {
      return res;
    }
    return generate(1, n);
  }

 private:
  //生成从start-end的所有可能的二叉搜索树
  //对于这个问题来说，start-end是连续的
  std::vector<TreeNode *> generate(int start, int end) {
    std::vector<TreeNode *> subTree;
    if (start > end) {
      subTree.push_back(nullptr);
      return subTree;
    }
    //已k为根节点，先后生成所有可能的左右子树后连接
    for (int k = start; k <= end; k++) {
      std::vector<TreeNode *> leftSubs = generate(start, k - 1);
      std::vector<TreeNode *> rightSubs = generate(k + 1, end);
      for (auto i : leftSubs) {
        for (auto j : rightSubs) {
          TreeNode *node = new TreeNode(k);
          node->left = i;
          node->right = j;
          subTree.push_back(node);
        }
      }
    }
    return subTree;
  }
};
#endif