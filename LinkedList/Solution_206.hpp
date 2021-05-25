/*
 * @Author: Jie Lin
 * @Date: 2021-05-23 22:39:46
 * @LastEditTime: 2021-05-25 21:54:50
 * @LastEditors: Jie Lin
 * @Description:Reverse Linked List
 * @FilePath: \myleetcode\LinkedList\Solution_206.hpp
 *
 */
#ifndef SOLUTION_206
#define SOLUTION_206
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
/**
 * @brief  反转链表，基本知识要掌握
 * @note
 * @retval None
 */
class Solution_206 {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* node = nullptr;
    while (head) {
      auto tmp = head->next;
      head->next = node;
      node = head;
      head = tmp;
    }
    return node;
  }
};
#endif