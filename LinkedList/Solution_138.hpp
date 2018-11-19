#ifndef SOLUTION_138
#define SOLUTION_138
/* A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.

Return a deep copy of the list.
给定的链表有一个额外的随机指针域，对这个链表深复制一份

为了不重复制造节点
第一次遍历复制节点内容，但不对随机域操作
记录原链表指针和新链表指针的对应关系到map中
第二次遍历时确定随机域

不需要额外存储的方法是
在原有节点后面插入一个它的副本
随机域指向的节点的后一个就是新的副本指针
再将副本链表拆分出来即可
 */
#include <unordered_map>
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution_138 {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    auto newhead = new RandomListNode(-1);
    std::unordered_map<RandomListNode *, RandomListNode *> rec;
    auto cur = head;
    auto tail = newhead;
    while (cur) {
      tail->next = new RandomListNode(cur->label);
      rec[cur] = tail->next;
      cur = cur->next;
      tail = tail->next;
    }
    tail->next = nullptr;
    cur = head;
    tail = newhead->next;
    while (cur) {
      tail->random = rec[cur->random];
      cur = cur->next;
      tail = tail->next;
    }
    return newhead->next;
  }
  void test() {
    auto head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    head->next->next->next = nullptr;
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head;
    auto x = copyRandomList(head);
  }
};
class Solution_138_bak {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    //在原有节点后面插入其副本 A-A'-B-B'...
    for (auto *curr = head; curr; curr = curr->next->next) {
      auto *node = new RandomListNode(curr->label);
      node->next = curr->next;
      curr->next = node;
    }

    //更新副本的随机域，在上一步操作后，原有节点的随机域的副本在原随机域的后面一个
    for (auto *curr = head; curr; curr = curr->next->next) {
      if (curr->random) {
        curr->next->random = curr->random->next;
      }
    }

    // 将副本链表分离出来
    RandomListNode dummy(0);
    for (auto *curr = head, *copy_curr = &dummy; curr;
         copy_curr = copy_curr->next, curr = curr->next) {
      copy_curr->next = curr->next;
      curr->next = curr->next->next;  //原链表恢复链接次序
    }
    return dummy.next;
  }
};
#endif