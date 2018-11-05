#ifndef SOLUTION_92
#define SOLUTION_92
/* Reverse a linked list from position m to n.
Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.
将一个链表的中间一段倒过来
记录m前一个元素
倒置序列的最后一个节点其实是最先加入倒置序列的节点
向后发现新节点
链表不能断，记录新加入倒置节点的后一个
新节点前置
倒置序列的最后一个节点的指针域设为上面的记录值

链表指来指去真是让人伤脑筋
*/
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution_92 {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    auto headofhead = new ListNode(-1);
    headofhead->next = head;
    auto res = headofhead;
    // 移动到m-1位置
    for (int i = 1; i <= m - 1; i++) {
      res = res->next;
    }
    auto tail = res->next;//res后面的一个为尾部，一直都是这个值
    for (int i = m + 1; i <= n; i++) {
      auto newhead = tail->next;
      auto temp = newhead->next;  // the node next to the new node
      newhead->next = res->next;
      res->next = newhead;
      tail->next = temp;
    }
    return headofhead->next;
  }
  void test() {
    ListNode head(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(4);
    head.next->next->next->next = new ListNode(5);
    auto x = reverseBetween(&head, 2, 4);
  }
};
#endif