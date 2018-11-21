#ifndef SOLUTION_143
#define SOLUTION_143
/* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes,
only nodes itself may be changed.

给出一个链表，按给出的顺序重新排列

设置两个指针，一个快一个慢，在链表中间截断
对后面链表逆序排列，逆序用到了25题里的方法
再把这两个链表合并即可
*/
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution_143 {
 public:
  void reorderList(ListNode* head) {
    auto slow = head, fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      if (!fast->next->next) {
        fast = fast->next;
        break;
      }
      fast = fast->next->next;
    }
    if (slow && fast) reverse(slow, fast);
    auto cur = head;
    //两个链表合并，注意slow->next=NULL
    //并且 前半截最后节点的next指向slow，在链表长度为偶数时会直接连起来
    //长度为奇数时前半截最后节点的next指向倒序后slow的前一个节点，也能直接连起来
    while (fast != slow) {
      auto temp1 = cur->next;
      auto temp2 = fast->next;
      fast->next = cur->next;
      cur->next = fast;
      cur = temp1;
      fast = temp2;
    }
  }
  //方法参数为要倒转的部分链表的第一个指针和最后一个节点指针
  //方法执行完后，front就变成了尾部，back变成头部
  void reverse(ListNode* front, ListNode* back) {
    auto temphead = front;  //已经倒转的链表头部
    auto end = back->next;  // back的后一节点作为终止条件
    auto ptr = front->next;
    while (ptr != end) {
      auto next = ptr->next;
      ptr->next = temphead;
      temphead = ptr;
      ptr = next;
    }
    //完成后front变成了尾部，要和原来尾部节点的next指针衔接
    front->next = end;
  }
};
#endif