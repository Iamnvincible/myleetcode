#ifndef SOLUTION_148
#define SOLUTION_148
/*
Sort a linked list in O(n log n) time using constant space complexity.

用O(nlogn)的时间、常数空间将链表排序
单链表适合用归并排序，可复用21题代码
双向链表用快排

 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
/*
法一，记录链表的长度
通过遍历长度的一半获得链表中部指针（法二使用快慢指针法，复杂度是一样的）
从中间断开，获得左右两个链表
通过递归排序思想实现排序
 */
class Solution_148 {
 public:
  ListNode* sortList(ListNode* head) {
    int length = 0;  //链表长度
    ListNode* p = head;
    ListNode* res = nullptr;
    //求链表长度
    while (p) {
      length++;
      p = p->next;
    }
    res = sort(head, length);
    return res;
  }

 private:
  //获得从head开始后的第steps个节点的指针
  ListNode* move(ListNode* head, int steps) {
    while (--steps) {
      head = head->next;
    }
    return head;
  }

  ListNode* sort(ListNode* head, int len) {
    ListNode* sorted = head;
    //长度大于1时才需要排序
    if (len > 1) {
      int half = len / 2;
      //获得链表中部指针
      ListNode* left_tail = move(head, half);
      //右边指针为中部节点的后一个
      ListNode* right_head = left_tail->next;
      left_tail->next = nullptr;  //链表断开
      //递归调用，分别排序左边和右边的两个链表
      ListNode* l1 = sort(head, half);
      ListNode* l2 = sort(right_head, len - half);
      //两边有序之后合并两个链表
      sorted = mergeTwoLists(l1, l2);
    }
    return sorted;
  }
  // 21题代码
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
/*
法二，
快慢指针法
是要简洁一点
 */
class Solution_148_back {
 public:
  ListNode* sortList(ListNode* head) {
    //判断不用排序的情况
    if (!head || !head->next) return head;
    //用快慢指针找到链表中部
    ListNode *fast = head, *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    //断开，使得两端为两个独立的链表，以便复用合并代码
    fast = slow;
    slow = slow->next;
    fast->next = nullptr;  //关键，断开链表
    //左边以head开始，右边以slow开始
    ListNode* left = sortList(head);
    ListNode* right = sortList(slow);
    //左右为有序之后，合并即可
    return mergeTwoLists(left, right);
  }

 private:
  // 21题代码
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