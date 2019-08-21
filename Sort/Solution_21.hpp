#ifndef SOLUTION_21
#define SOLUTION_21
/*
Merge two sorted linked lists and return it as a new list. The new list should
be made by splicing together the nodes of the first two lists.

合并两个有序链表
申请一个头节点，通过比较两个链表头部值的大小附加到头节点后面
然后头节点和附加的节点链表头部指针后移
直到有一个链表走到头
将另一个链表直接附到头节点后面即可

注意开始要记录头节点的地址
因为后面头节点会一直往后，充当有序链表的最后一个节点
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution_21 {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    auto head = new ListNode(0);
    auto res = head;
    while (l1 && l2) {
      if (l1->val >= l2->val) {
        head->next = l2;
        l2 = l2->next;
      } else {
        head->next = l1;
        l1 = l1->next;
      }
      head = head->next;
    }
    head->next = l1 ? l1 : l2;
    return res->next;
  }
};
#endif