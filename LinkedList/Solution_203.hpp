/*
 * @Author: Jie Lin
 * @Date: 2021-05-25 21:57:28
 * @LastEditTime: 2021-05-25 22:11:36
 * @LastEditors: Jie Lin
 * @Description:Remove Linked List Elements
 * @FilePath: \myleetcode\LinkedList\Solution_203.hpp
 *
 */
#ifndef SOLUTION_203
#define SOLUTION_203
#include "ListNode.h"
/**
 * @brief  在链表中删除所有节点值为给定数的节点，返回新链表头指针
 * @note
 * @retval None
 */
class Solution_203 {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode res(-1, head);
    ListNode* node = res.next;
    ListNode* pre = &res;
    while (node) {
      if (node->val == val) {
        pre->next = node->next;
        delete (node);
        node = pre->next;
      } else {
        pre = node;
        node = pre->next;
      }
    }
    return res.next;
  }
};
#endif