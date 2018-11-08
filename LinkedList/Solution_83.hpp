#ifndef SOLUTION_83
#define SOLUTION_83
/* Given a sorted linked list,
delete all duplicates such that each element appear only once.
在排好序的链表中删除重复元素
记得要释放内存
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    auto cur = head;
    while (cur && cur->next) {
      if (cur->val == cur->next->val) {
        auto temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
      } else {
        cur = cur->next;
      }
    }
    return head;
  }
};
#endif