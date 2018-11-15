#ifndef SOLUTION_24
#define SOLUTION_24
/*
Given a linked list,
swap every two adjacent nodes and return its head.
Note:
Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
给出链表，每一对节点交换前后顺序
其实简洁的方法只要交换节点里面的val就可以了
但是题目说不要这样

遍历一遍，设置两个指针交换，再接到前一个后面
 */
#include <algorithm>
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution_24 {
 public:
  ListNode* swapPairs(ListNode* head) {
    auto ori = head;
    while (head && head->next) {
      auto pre = head;
      auto lat = pre->next;
      std::swap(pre->val, lat->val);
      head = lat->next;
    }
    return ori;
  }
};
class Solution_24_bak {
 public:
  ListNode* swapPairs(ListNode* head) {
    auto headofhead = new ListNode(-1);
    headofhead->next = head;
    auto pre = headofhead;
    while (pre && pre->next && pre->next->next) {
      auto a = pre->next;
      auto b = a->next;
      pre->next = b;
      a->next = b->next;
      b->next = a;
      pre = a;
    }
    return headofhead->next;
  }
};
#endif