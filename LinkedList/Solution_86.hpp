#ifndef SOLUTION_86
#define SOLUTION_86
/* Given a linked list and a value x,
partition it such that all nodes
less than x come before
nodes greater than or equal to x.

You should preserve the original relative order of the nodes
in each of the two partitions.
给出一个链表和值x，
把值比x小的放在比x大或和x相等的前面
同时保持原有数字的相对位置

把链表分为比x小的一段和不比x小的一段，最后连接即可
*/
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution_86 {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode headofhead(-1);
    headofhead.next = head;
    ListNode* lessnode = &headofhead;

    ListNode greatnode(-1);
    ListNode* greattail = &greatnode;

    ListNode* cur = head;
    while (cur) {
      if (cur->val < x) {
        lessnode->next = cur;
        lessnode = cur;
      } else {
        greattail->next = cur;
        greattail = cur;
      }
      cur = cur->next;
    }
    greattail->next = nullptr;
    lessnode->next = greatnode.next;
    return headofhead.next;
  }
  void test() {
    ListNode head(1);
    head.next = new ListNode(4);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(2);
    head.next->next->next->next = new ListNode(5);
    head.next->next->next->next->next = new ListNode(2);
    auto x = partition(&head, 3);
    x->val;
  }
};
#endif