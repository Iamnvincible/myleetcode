#ifndef SOLUTION_19
#define SOLUTION_19
/*
Given a linked list,
remove the n-th node from the end of list and return its head.
给定链表，删去从后往前的第n个节点
朴素的想法是
先遍历求得链表长度
再遍历到要删除节点的前一个节点
连接前一节点与后一节点

只遍历一遍的想法
要删掉最后第n个节点，必须要先找到第length-n个节点
可以设置两个指针，一个先走n步
另一个在前一个走了n步之后和前一个一起往后走
直到前一个走到尾部，这个指针就走到了第length-n个节点

 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution_19 {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // if (!head || n < 1) return head;
    ListNode headofhead(-1);
    headofhead.next = head;
    auto cur = head;
    int count = 0;
    while (cur) {
      cur = cur->next;
      count++;
    }
    cur = &headofhead;
    int move = count - n;
    while (move--) {
      cur = cur->next;
    }
    auto remove = cur->next;
    cur->next = remove->next;
    delete remove;
    return headofhead.next;
  }
};
class Solution_19_bak {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode headofhead(-1);
    headofhead.next = head;
    auto p = &headofhead;
    auto q = &headofhead;
    while (n--) {
      p = p->next;
    }
    while (p->next) {
      p = p->next;
      q = q->next;
    }
    auto temp = q->next;
    q->next = temp->next;
    delete temp;
    return headofhead.next;
  }
};
#endif