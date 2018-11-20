#ifndef SOLUTION_141
#define SOLUTION_141

/* Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
给出一个可能存在环的链表，判断是否存在环

一种方法记录以及遍历过的节点，对新节点判断一下就好了

另一种只需要O(1)的空间
维护两个指针，一个一次走一步，一个一次走两步
如果两个指针走到一块了，说明存在环
从数学的角度来看，相当于有环的情况下，一个不走一个走，必然会相遇
*/
#include <unordered_map>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution_141 {
 public:
  bool hasCycle(ListNode *head) {
    std::unordered_map<ListNode *, bool> rec;
    while (head) {
      if (rec.find(head) != rec.end()) {
        return true;
      } else {
        rec[head] = true;
        head = head->next;
      }
    }
    return false;
  }
};
class Solution_141_bak {
 public:
  bool hasCycle(ListNode *head) {
    auto slow = head, fast = head;
    // fast走得快，不需要再对slow判断
    //要保证fast->next->next有合法值
    //首先fast不能是null，fast->next也不能是null
    //这个判断条件相当于fast先走一步，再走一步
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};
#endif