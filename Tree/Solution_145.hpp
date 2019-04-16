#ifndef SOLUTION_145
#define SOLUTION_145
#include <stack>
#include <vector>
//节点结构体
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution_145 {
 public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> res;
    postorder(root, res);
    return res;
  }

 private:
  void postorder(TreeNode *root, std::vector<int> &res) {
    if (root != nullptr) {
      postorder(root->left, res);
      postorder(root->right, res);
      res.push_back(root->val);
    }
    return;
  }
};
class Solution_145_back {
 public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> s;
    //先将根节点入栈
    s.push(root);
    //当栈不为空且根节点不为空情况下循环
    while (!s.empty() && root != nullptr) {
      //获得栈顶元素并将其出栈
      auto top = s.top();
      s.pop();
      //如果top的左右节点都是空，说明这是一个叶子节点或已经遇到过的某个根节点
      //可以读取节点值，直接进入下一轮循环
      if (top->left == nullptr && top->right == nullptr) {
        res.push_back(top->val);
        continue;
      }
      //当top不是叶子时，用temp保存其值的副本，用一个左右节点为空的节点代替其入栈
      //保证下一次遇到时能够直接读取
      auto temp = new TreeNode(top->val);
      s.push(temp);
      //当top的右节点不为空时入栈，左节点不为空时也入栈
      //先进后出，保证左-右-中的后序遍历顺序
      if (top->right != nullptr) {
        s.push(top->right);
      }
      if (top->left != nullptr) {
        s.push(top->left);
      }
    }
    return res;
  }
};
class Solution_145_back2 {
 public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> s;
    TreeNode *p = root, *q = nullptr;
    do {
      // p一直往左下，一直入栈直到p为空
      while (p != nullptr) {
        s.push(p);
        p = p->left;
      }
      q = nullptr;
      while (!s.empty()) {
        //取栈顶，并出栈
        p = s.top();
        s.pop();
        //右节点为空/已经访问过，访问p节点
        // p为最左下的节点，只要右节点不为空，即可读取其值
        if (p->right == q) {
          res.push_back(p->val);
          //用q保存已经访问过的位置，用于后序遍历往回走
          q = p;
        } else {
          //右节点不为空，将其入栈
          //并指向右节点，进入下一轮while循环
          s.push(p);
          p = p->right;
          break;
        }
      }

    } while (!s.empty());

    return res;
  }
};

class Solution_145_back3 {
 public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> res;
    TreeNode dummy(-1);
    TreeNode *cur, *prev = nullptr;
    dummy.left = root;
    cur = &dummy;
    while (cur != nullptr) {
      //如果左节点为空，先遍历右子树
      if (cur->left == nullptr) {
        prev = cur;
        cur = cur->right;
      } else {
        //左节点不为空，找到cur节点在中序遍历中的前驱节点
        TreeNode *node = cur->left;
        while (node->right != nullptr && node->right != cur) {
          node = node->right;
        }
        //如果前驱节点的右节点为空，说明没有建立线索
        //将其右指针指向cur节点
        // pre记录为cur
        // cur移动到左节点
        if (node->right == nullptr) {
          node->right = cur;
          prev = cur;
          cur = cur->left;
        } else {
          //如果前驱节点的右节点是cur节点，已经建立过线索
          //反向读取，cur左节点到pre直接的节点值
          //重置pre的右节点为空
          //记录pre为cur
          // cur移至右节点，在遍历完左子树后遍历右子树
          visit_reverse(cur->left, prev, res);
          prev->right = nullptr;
          prev = cur;
          cur = cur->right;
        }
      }
    }
    return res;
  }

 private:
  //将节点from 和 to的顺序倒置
  void reverse(TreeNode *from, TreeNode *to) {
    TreeNode *x = from, *y = from->right, *z;
    if (from == to) return;
    while (x != to) {
      z = y->right;
      y->right = x;
      x = y;
      y = z;
    }
  }
  //从from到to的逆序访问，即从to向上访问树的节点到from节点
  void visit_reverse(TreeNode *from, TreeNode *to, std::vector<int> &res) {
    TreeNode *p = to;
    //先倒置
    reverse(from, to);
    while (true) {
      res.push_back(p->val);
      if (p == from) {
        break;
      }
      p = p->right;
    }
    //再倒置回来，保持原有树的结构
    reverse(to, from);
  }
};
#endif