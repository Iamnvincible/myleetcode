#ifndef SOLUTION_105
#define SOLUTION_105
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
给出二叉树先序和中序遍历序列，还原二叉树
1.根节点为先序遍历的第一个元素
2.用根节点将中序遍历序列分为两个部分，前一个部分是左子树，后一个部分是右子树
3.对于左子树，找出左子树元素在先序和中序遍历中的部分，递归1，2两步，直到先序和中序序列为空
4.对于右子树，找出右子树元素在先序和中序遍历中的部分，递归1，2两步，直到先序和中序序列为空
5.返回根节点指针
 */
#include <algorithm>
#include <vector>
#include "TreeNode.h"
//按照步骤，把每个先序/中序部分找出来新建vector递归
class Solution_105 {
 public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if (preorder.empty() || inorder.empty() ||
        preorder.size() != inorder.size()) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(*preorder.begin());
    // split
    auto pos = std::find(inorder.begin(), inorder.end(), root->val);
    std::vector<int> leftinorder(inorder.begin(), pos);
    auto prebegin = preorder.begin() + 1;
    auto preend = prebegin + leftinorder.size();
    std::vector<int> leftpreorder(prebegin, preend);
    root->left = buildTree(leftpreorder, leftinorder);
    std::vector<int> rightinorder(pos + 1, inorder.end());
    std::vector<int> rightpreorder(preend, preorder.end());
    root->right = buildTree(rightpreorder, rightinorder);

    return root;
  }
};
//上面的方法对每个新的向量新建，消耗了大量空间
//这种方法利用迭代器，减少先进向量，只记录指针位置
class Solution_105_back {
 public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return build(preorder.begin(), preorder.end(), inorder.begin(),
                 inorder.end());
  }

 private:
  TreeNode* build(std::vector<int>::iterator preleft,
                  std::vector<int>::iterator preright,
                  std::vector<int>::iterator inleft,
                  std::vector<int>::iterator inright) {
    if (preleft == preright || inleft == inright) {
      return nullptr;
    }
    //根节点为先序遍历的第一个元素
    TreeNode* root = new TreeNode(*preleft);
    //找出根节点在中序遍历中的位置
    auto inmid = std::find(inleft, inright, root->val);
    //左子树长度
    auto len = inmid - inleft;
    //左子树先序起始元素
    auto leftpreleft = preleft + 1;
    //左子树先序尾
    auto leftpreright = leftpreleft + len;
    //左子树中序起始元素
    auto leftinleft = inleft;
    //左子树中序尾
    auto leftinright = inmid;
    root->left = build(leftpreleft, leftpreright, leftinleft, leftinright);
    //右子树先序起始元素
    auto rightpreleft = leftpreright;
    //右子树先序尾
    auto rightpreright = preright;
    //右子树中序起始元素
    auto rightinleft = inmid + 1;
    //右子树中序尾
    auto rightinright = inright;
    root->right = build(rightpreleft, rightpreright, rightinleft, rightinright);
    return root;
  }
};

#endif