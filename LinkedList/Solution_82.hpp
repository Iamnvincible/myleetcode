#ifndef SOLUTION_82
#define SOLUTION_82
/*
 *Given a sorted linked list,
 delete all nodes that have duplicate numbers,
 leaving only distinct numbers from the original list.
 给出排序的链表，返回去掉所有重复元素后的链表
 即只有出现一次的元素
当前元素和后一个元素比较，重复则记录重复元素，并删除当前元素
不重复则添加到返回链表的尾部
*/
#include <iostream>
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution_82 {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode headofhead(-1);
    auto tail = &headofhead;
    auto cur = head;
    ListNode* temp = nullptr;
    while (cur) {
      if (temp && cur->val == temp->val) {
        auto dump = cur;
        cur = cur->next;
        delete dump;
      } else if (cur->next && cur->val == cur->next->val) {
        temp = new ListNode(cur->val);
        auto dump = cur;
        cur = cur->next;
        delete dump;
      } else {
        tail->next = cur;
        tail = cur;
        cur = cur->next;
        tail->next = nullptr;
        // delete temp;
      }
    }
    return headofhead.next;
  }
  void test() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    auto x = deleteDuplicates(head);
    std::cout << x->val << std::endl;
  }
};
#endif