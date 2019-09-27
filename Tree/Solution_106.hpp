#ifndef SOLUTION_106
#define SOLUTION_106
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
给出中选和后续遍历序列，还原二叉树
1.后续遍历的最后一个元素是根节点
2.在中序遍历中，根节点左边的元素是左子树，右边的是右子树，记录各自部分
3.在后续遍历中找到左子树元素，递归1，2
4.在后续遍历中找到右子树元素，递归1，2
5.返回根节点
类似105题
 */
#include <algorithm>
#include <vector>
#include "TreeNode.h"
class Solution_106 {
 public:
  TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    return build(inorder.begin(), inorder.end(), postorder.begin(),
                 postorder.end());
  }

 private:
  TreeNode* build(std::vector<int>::iterator inleft,
                  std::vector<int>::iterator inright,
                  std::vector<int>::iterator postleft,
                  std::vector<int>::iterator postright) {
    if (inleft == inright || postleft == postright) {
      return nullptr;
    }
    //为方便阅读变量名较多，可以简化
    TreeNode* root = new TreeNode(*(postright - 1));
    auto pos = std::find(inleft, inright, root->val);
    auto leftinleft = inleft;
    auto leftinright = pos;
    auto leftpostleft = postleft;
    auto leftpostright = postleft + (pos - inleft);
    root->left = build(leftinleft, leftinright, leftpostleft, leftpostright);
    auto rightinleft = pos + 1;
    auto rightinright = inright;
    auto rightpostleft = leftpostright;
    auto rightpostright = postright - 1;
    root->right =
        build(rightinleft, rightinright, rightpostleft, rightpostright);
    return root;
  }
};
#endif