#ifndef BST
#define BST
#include "TreeNode.h"
class bst {
 private:
  void addnode(TreeNode *root, int val) {
    if (!root) {
      root = new TreeNode(val);
    } else if (val > root->val) {
      if (!root->right) {
        root->right = new TreeNode(val);
      } else {
        addnode(root->right, val);
      }
    } else if (val < root->val) {
      if (!root->left) {
        root->left = new TreeNode(val);
      } else {
        addnode(root->left, val);
      }
    } else {
      return;
    }
  }

 public:
  TreeNode *root;
  bst() : root(nullptr) {}
  void Insert(int val) {
    if (!root) {
      root = new TreeNode(val);
    } else {
      addnode(root, val);
    }
  }
};

#endif