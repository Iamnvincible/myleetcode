/*
 * @Author: Jie Lin
 * @Date: 2021-05-25 21:55:42
 * @LastEditTime: 2021-05-25 22:08:31
 * @LastEditors: Jie Lin
 * @Description:链表节点结构体
 * @FilePath: \myleetcode\LinkedList\ListNode.h
 *
 */
#ifndef LISTNODE
#define LISTNODE
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#endif