#ifndef SOLUTION_2_C
#define SOLUTION_2_C
/* You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero,
except the number 0 itself.
把两个链表的数字代表的倒序数字求和
注意长度和进位
*/
#include <stdlib.h>
struct ListNode {
  int val;
  struct ListNode* next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  int add = 0;
  struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode* tail = res;
  res->next = NULL;
  while (l1 != NULL || l2 != NULL || add == 1) {
    int temp = 0;
    if (l1 != NULL) {
      temp += l1->val;
      l1 = l1->next;
    }
    if (l2 != NULL) {
      temp += l2->val;
      l2 = l2->next;
    }
    if (add != 0) {
      temp += add;
    }
    add = temp / 10;
    temp = temp % 10;
    struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
    n->val = temp;
    n->next = NULL;
    tail->next = n;
    tail = n;
  }
  return res->next;
}
#endif