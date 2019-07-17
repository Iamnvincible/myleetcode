#ifndef SOLUTION_99
#define SOLUTION_99
#include <stack>
#include <vector>
#include "TreeNode.h"
/*
因为正确的二叉搜索树的中序遍历是从小到大的
交换了其中两个节点的二叉树就好像是一个从小到大排列的数组交换了两个数字
这两个数字就会形成一个峰值，一个谷值，找到这两个值交换回来即可
对于峰值，它比后一个元素大；对于谷值，它比前一个元素小
对二叉树中序遍历，把节点指针保存起来，找到两个节点之后交换节点值
中序遍历见题94
*/
class Solution_99 {
 public:
  void recoverTree(TreeNode *root) {
    std::vector<TreeNode *> tree;
    //先中序遍历树，把每个节点指针放到集合中
    inorder(root, tree);
    TreeNode *left = nullptr, *right = nullptr;
    if (tree.size() > 1) {
      //在集合中从左到右遍历，找到一个比右边元素大的节点
      for (size_t i = 0; i < tree.size(); i++) {
        if (tree[i]->val > tree[i + 1]->val) {
          left = tree[i];
          break;
        }
      }
      //从右往左遍历，找到一个比左边元素小的节点
      for (size_t i = tree.size() - 1; i > 0; i--) {
        if (tree[i]->val < tree[i - 1]->val) {
          right = tree[i];
          break;
        }
      }
      //交换两个节点中的值即可
      int temp = left->val;
      left->val = right->val;
      right->val = temp;
    }
  }

 private:
  //递归的中序遍历
  void inorder(TreeNode *root, std::vector<TreeNode *> &tree) {
    if (root) {
      inorder(root->left, tree);
      tree.push_back(root);
      inorder(root->right, tree);
    }
    //非递归中序遍历
    // std::stack<TreeNode *> s;
    // while (!s.empty() || root) {
    //   if (root) {
    //     s.push(root);
    //     root = root->left;
    //   } else {
    //     auto node = s.top();
    //     tree.push_back(node);
    //     s.pop();
    //     root = node->right;
    //   }
    // }
  }
};
/*
为了不开一个和树一样大的存储空间
可以保存中序遍历过程中的前后两个节点指针
判断其大小关系
前一个比后一个大，那么前一个必然是被交换过的节点
为了寻找后一个被交换的节点，
需要的条件也是前一个比后一个大，
但交换节点是后一个，
因为条件一样，所以需要遍历完树才能确定
为了不用到栈，遍历树时使用Morris遍历
 */
class Solution_99_back {
 public:
  void recoverTree(TreeNode *root) {
    auto cur = root;
    TreeNode *pre = nullptr, *left = nullptr, *right = nullptr;
    TreeNode **lleft = &left, **rright = &right;
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        detect(pre, cur, lleft, rright);
        pre = cur;
        cur = cur->right;
      } else {
        auto node = cur->left;
        //找到cur在中序遍历下的前驱
        while (node->right != nullptr && node->right != cur) {
          node = node->right;
        }
        if (node->right == nullptr) {
          node->right = cur;  //建立线索
          cur = cur->left;    //移到左子树（不为空）
        } else {
          detect(pre, cur, lleft, rright);
          pre = cur;
          node->right = nullptr;
          cur = cur->right;
        }
      }
    }
    //交换两个节点中的值即可
    if (left && right) {
      int temp = left->val;
      left->val = right->val;
      right->val = temp;
    }
  }
  void test() {
    TreeNode root(1);
    root.left = new TreeNode(3);
    root.left->right = new TreeNode(2);
    recoverTree(&root);
  }

 private:
  void detect(TreeNode *pre, TreeNode *cur, TreeNode **left, TreeNode **right) {
    if (pre && pre->val > cur->val) {
      if (!*left) {
        *left = pre;
      }
      //关键，每次满足条件时更新，最后一次的结果是要换的节点
      //因为从前往后一次遍历不知道后面的情况
      *right = cur;
    }
  }
};
#endif