#ifndef SOLUTION_25
#define SOLUTION_25
/*
Given a linked list,
reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked
list. If the number of nodes is not a multiple of k then left-out nodes in the
end should remain as it is.

给出链表和正整数k
把链表元素分成每组个数为k的若干组
组内倒转元素次序，不足k的组不变

写一个方法来对给出的链表两个节点之间的元素倒转
对找出来的连续k个节点调用这个方法
注意链表头尾的衔接
 */
#include <algorithm>
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution_25 {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    int count = 1;
    auto headofhead = new ListNode(-1);
    headofhead->next = head;
    auto tail = headofhead;
    while (head) {
      //寻找连续的一组k个元素
      while (count < k && head) {
        head = head->next;
        count++;
      }
      //判断一组有没有k个元素
      if (head) {
        //这里的head表示一组中的最后一个节点
        //准备front和back
        // front是这组节点的第一个，back是最后一个
        auto front = tail->next;
        auto back = head;
        //调用倒转部分链表方法
        reverse(front, back);
        //调用完成后front、back意义互换
        //在前一组的尾部接上当前组的头部
        tail->next = back;
        //新的尾部变成这一组的尾部，衔接完成
        tail = front;
        //将head指代为下一组的头部
        head = front->next;
        //重置计数器
        count = 1;
      }
    }
    return headofhead->next;
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
  void test() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    auto end = head->next->next->next;
    reverse(head, end);
  }
};
//递归思路
//先找下一组的头
//再找下一组倒转完成之后的头
//对本组倒转
class Solution_25_bak {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k < 2) return head;
    // next_group来表示可能的下一组的头节点
    // head为当前组头部
    ListNode* next_group = head;
    for (int i = 0; i < k; ++i) {
      //当next_group没走到尾部且i！=k时
      if (next_group)
        next_group = next_group->next;
      else
        //否则说明本组不足k个节点，不必操作
        return head;
    }
    //如果上面的循环没有return， next_group表示当前组的下一组的头节点
    // new next group 是倒转好之后的下一组的头节点
    ListNode* new_next_group = reverseKGroup(next_group, k);
    ListNode *prev = NULL, *cur = head;
    while (cur != next_group) {
      ListNode* next = cur->next;
      //当前节点的next是前一个节点，实现倒转
      //如果前一个是null
      cur->next =
          prev ? prev
               : new_next_group;  // cur->next=prev!=NULL?prev:new_next_group;
      prev = cur;
      cur = next;
    }
    //返回倒转后的本组头节点
    return prev;
  }
};
#endif