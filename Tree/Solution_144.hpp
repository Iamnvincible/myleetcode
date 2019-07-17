#ifndef SOLUTION_144
#define SOLUTION_144
#include <stack>
#include <vector>
#include "TreeNode.h"
/* 二叉树先序遍历
有递归，非递归两种
其中非递归还有一种Morris Traversal可以实现O(1)空间 线性时间
 */

//递归
//先得到当前节点值，再遍历左右子树
class Solution_144 {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> res;
    if (root == NULL) {
      return res;
    } else {
      preorder(root, res);
    }
    return res;
  }

 private:
  //注意这里使用对vector的引用&
  void preorder(TreeNode *root, std::vector<int> &vec) {
    if (root != NULL) {
      vec.push_back(root->val);
      preorder(root->left, vec);
      preorder(root->right, vec);
    }
  }
};
//非递归
//使用栈
//先将根节点入栈
//循环判断栈空，先入栈右指针，再入栈左指针，出栈时就能先访问左边
class Solution_144_bak {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> stk;
    if (root == nullptr) {
      return res;
    }
    stk.push(root);
    while (!stk.empty()) {
      auto node = stk.top();
      stk.pop();
      res.push_back(node->val);
      if (node->right != nullptr) {
        stk.push(node->right);
      }
      if (node->left != nullptr) {
        stk.push(node->left);
      }
    }
    return res;
  }
};
// Morris Traversal
/*
要使用 O(1)空间进行遍历，最大的难点在于，
遍历到子节点的时候怎样重新返回到父节点（假设节点中没有指向父节点的p指针。
Morris 方法用到了
线索二叉树（threaded binary tree）。
不需要为每个节点额外分配指针指向其前驱（predecessor）和后继节点（successor），
只需要利用叶子节点中的
左右空指针
指向某种顺序遍历下的
前驱节点或后继节点就可以了。

 */
class Solution_144_bak_2 {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> res;
    auto cur = root;
    while (cur != nullptr) {
      //遍历根节点
      //左节点为空，往右节点遍历//简单情况
      if (cur->left == nullptr) {
        res.push_back(cur->val);
        cur = cur->right;
      } else {
        //左节点不为空，保存左节点指针
        auto node = cur->left;
        //遍历到左节点的右节点为空，即找出cur节点在中序遍历下的前驱节点
        //结束条件为找到中序遍历的前驱或遇到自己(在前面的操作中已经建立线索)
        while (node->right != nullptr && node->right != cur) {
          node = node->right;
        }
        //此时node为cur在中序遍历下的前驱
        //如果node右节点是NULL，说明还没有建立线索
        //读取当前节点值（因为是先序，根节点先）
        //如果是中序，要将node的右节点设为cur，作为node的后继节点，符合中序的顺序
        //将这个节点的右指针指向cur，！建立线索！
        //将cur指向其左节点
        if (node->right == nullptr) {
          res.push_back(cur->val);  //中序遍历没有这一步
          node->right = cur;        //建立线索
          cur = cur->left;
        } else {
          //如果右节点不为空，说明已经存在线索
          //将其置为空，删除线索，恢复树的原有结构
          //再将cur指向其右节点
          //如果是中序遍历，先保存cur节点的数据
          // res.push_back(cur->val)
          node->right = nullptr;
          cur = cur->right;
        }
      }
    }

    return res;
  }
};
#endif