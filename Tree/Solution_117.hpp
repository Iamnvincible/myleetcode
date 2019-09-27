#ifndef SOLUTION_117
#define SOLUTION_117
/*
Populate each next pointer to point to its next right node. If there is no next
right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:
    You may only use constant extra space.
    Recursive approach is fine, implicit stack space does not count as extra
space for this problem.
将二叉树同一层的节点用next指针连接
最右侧节点next为空
*/
#include <queue>
struct Node {
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node() {}

  Node(int _val, Node* _left, Node* _right, Node* _next) {
    val = _val;
    left = _left;
    right = _right;
    next = _next;
  }
};
/*
用队列来层序遍历
记录每一层的节点数，最后一个节点没有next
 */
class Solution_117 {
 public:
  Node* connect(Node* root) {
    std::queue<Node*> s;
    if (root) {
      s.push(root);
    }
    while (!s.empty()) {
      int size = s.size();  //记录一层的节点数
      while (size--) {
        auto left = s.front();  //取一个节点
        s.pop();
        //当当前层还有节点时，将s的next赋值为队列头
        if (size) {
          auto right = s.front();
          left->next = right;
        }
        //将下一层的节点入栈
        if (left->left) {
          s.push(left->left);
        }
        if (left->right) {
          s.push(left->right);
        }
      }
    }
    return root;
  }
};
//递归
class Solution_117_back2 {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) return root;
    Node* p = root->next;  //先获取next指针
    //当next指针不为空，即不是只有一个节点的层
    //获取一个兄弟节点
    while (p) {
      //如果left非空，p指向left，跳出循环
      if (p->left) {
        p = p->left;
        break;
      }
      //如果right非空，p指向right，跳出循环
      if (p->right) {
        p = p->right;
        break;
      }
      //如果p没有子节点，跳到下一个兄弟节点
      p = p->next;
    }
    //如果root的右节点非空，next赋值为p
    if (root->right) {
      root->right->next = p;
    }
    //如果root的左节点非空，next赋值为其右节点，当右节点为空时赋值为p
    if (root->left) {
      root->left->next = root->right ? root->right : p;
    }
    //跳到下一层
    //从右往左赋值
    connect(root->right);
    connect(root->left);

    return root;
  }
};
class Solution_117_back {
 public:
  Node* connect(Node* root) {
    if (!root) return root;
    auto res = root;
    //外层循环从上到下遍历
    //内层循环遍历一层中的节点
    while (root) {
      Node* next = nullptr;  //下一层的第一个节点
      Node* curr = nullptr;  //当前层需要赋予next指针域的节点
      while (root) {
        if (!next) {
          //本层第一次进的时候寻找下一层的第一个节点
          next = root->left ? root->left : root->right;
        }
        // root的left和right必然有一个非null
        //初始时，curr为null，先取得本层的第一个节点
        // curr不为null时，为curr的next指针域赋值
        //赋值后curr跳转
        //非常巧妙
        if (root->left) {
          if (curr) {
            curr->next = root->left;
          }
          curr = root->left;
        }
        if (root->right) {
          if (curr) {
            curr->next = root->right;
          }
          curr = root->right;
        }
        //转到上一层的后一个节点
        root = root->next;
      }
      //转到下一层
      root = next;
    }
    return res;
  }
};
class Solution_117_back3 {
 public:
  Node* connect(Node* root) {
    Node* dummy = new Node(0, NULL, NULL, NULL);  //临时节点，用来连接下一层
    Node* cur = dummy;  //表示需要需要next指针的节点
    Node* head = root;
    while (root) {
      if (root->left) {
        cur->next = root->left;
        cur = cur->next;  // cur往后走，保证cur是正需要赋值next指针的节点
      }
      if (root->right) {
        cur->next = root->right;
        cur = cur->next;
      }
      root = root->next;
      //当走到一层最右侧节点时
      if (!root) {
        cur = dummy;         // cur重置为dummy
        root = dummy->next;  // root指向下一层
        dummy->next = NULL;  //跳出当前层
      }
    }
    return head;
  }
};
#endif
/* 测试用例
{
    "Input": {
        "$id": "1",
        "left": {
            "$id": "2",
            "left": {
                "$id": "3",
                "left": null,
                "next": null,
                "right": null,
                "val": 4
            },
            "next": null,
            "right": {
                "$id": "4",
                "left": null,
                "next": null,
                "right": null,
                "val": 5
            },
            "val": 2
        },
        "next": null,
        "right": {
            "$id": "5",
            "left": null,
            "next": null,
            "right": {
                "$id": "6",
                "left": null,
                "next": null,
                "right": null,
                "val": 7
            },
            "val": 3
        },
        "val": 1
    },
    "Output": {
        "$id": "1",
        "left": {
            "$id": "2",
            "left": {
                "$id": "3",
                "left": null,
                "next": {
                    "$id": "4",
                    "left": null,
                    "next": {
                        "$id": "5",
                        "left": null,
                        "next": null,
                        "right": null,
                        "val": 7
                    },
                    "right": null,
                    "val": 5
                },
                "right": null,
                "val": 4
            },
            "next": {
                "$id": "6",
                "left": null,
                "next": null,
                "right": {
                    "$ref": "5"
                },
                "val": 3
            },
            "right": {
                "$ref": "4"
            },
            "val": 2
        },
        "next": null,
        "right": {
            "$ref": "6"
        },
        "val": 1
    }
}
 */