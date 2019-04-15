#ifndef SOLUTION_94
#define SOLUTION_94
#include <stack>
#include <vector>
//节点结构体
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution_94 {
 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> res;
    inorder(root, res);
    return res;
  }

 private:
  void inorder(TreeNode *root, std::vector<int> &res) {
    if (root != nullptr) {
      inorder(root->left, res);
      res.push_back(root->val);
      inorder(root->right, res);
    }
    return;
  }
};
class Solution_94_bak {
 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> s;
    //先将根节点入栈
    s.push(root);
    //当栈非空且root不为空
    while (!s.empty() && root != nullptr) {
      //读取栈顶元素并将其出栈
      auto top = s.top();
      s.pop();
      //如果栈顶的左节点为空，说明左子树为空，可以读取top的值
      //如果它的又节点不为空，将右节点入栈
      if (top->left == nullptr) {
        res.push_back(top->val);
        if (top->right != nullptr) {
          s.push(top->right);
        }
      } else {
        //栈顶左节点不为空，左子树要先读取
        //但是先考虑到右子树不为空时，先将右子树入栈
        //再将top节点的*值
        //入栈，temp是top的副本，左右子树为空，在下次遇到时能直接读取
        //最后把左子树入栈，后进先出，满足左-中-右的中序遍历顺序
        if (top->right != nullptr) {
          s.push(top->right);
        }
        auto temp = new TreeNode(top->val);
        s.push(temp);
        s.push(top->left);
      }
    }
    return res;
  }
};
class Solution_94_bak2 {
 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> s;
    auto p = root;
    //当栈非空或指针不为空时进入循环
    while (!s.empty() || p != nullptr) {
      //如果指针不为空
      //根节点入栈，并将p指向左子树
      //满足左-根-右次序
      if (p != nullptr) {
        s.push(p);
        p = p->left;
      } else {
        //如果指针为空，说明p的父节点的左子树为空，输出父节点值
        //并将右节点入栈
        p = s.top();
        s.pop();
        res.push_back(p->val);
        p = p->right;
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
class Solution_144_bak_3 {
 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
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
          // res.push_back(cur->val);  //中序遍历没有这一步
          node->right = cur;  //建立线索
          cur = cur->left;
        } else {
          //如果右节点不为空，说明已经存在线索
          //将其置为空，删除线索，恢复树的原有结构
          //再将cur指向其右节点
          //如果是中序遍历，先保存cur节点的数据
          res.push_back(cur->val);
          node->right = nullptr;
          cur = cur->right;
        }
      }
    }
    return res;
  }
};
#endif