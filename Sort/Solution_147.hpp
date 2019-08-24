#ifndef SOLUTION_147
#define SOLUTION_147
#include <cstdint>
/*
Sort a linked list using insertion sort.
Algorithm of Insertion Sort:
Insertion sort iterates, consuming one input element each repetition, and
growing a sorted output list. At each iteration, insertion sort removes one
element from the input data, finds the location it belongs within the sorted
list, and inserts it there. It repeats until no input elements remain.
用插入排序对一个链表从小到大排序
注意指针指向，复杂度为n^2
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution_147 {
 public:
  ListNode *insertionSortList(ListNode *head) {
    auto p = head;                  // p表示待加入节点
    auto pre_p = new ListNode(-1);  //表示p前面的节点
    auto pre_point = pre_p;
    auto order_head = new ListNode(-1);  //表示有序链表的头
    order_head->next = head;
    pre_p->next = p;
    //当链表不为空
    if (p != nullptr) {
      pre_p = p;
      p = p->next;
    }
    //当待排序链表长度>=1时才需要排序
    while (p) {
      auto temp = order_head->next;      //从链表第一个元素开始比较
      auto pre_temp = new ListNode(-1);  //记录比较元素的前一个元素
      auto pre_tempoint = pre_temp;
      pre_temp->next = temp;
      bool flag = false;  //记录是否越过了有序链表的第一个节点
      //如果待加入元素比链表中进行比较的元素大，则链表中节点后移
      while (p->val > temp->val) {
        pre_temp = temp;
        temp = temp->next;
        flag = true;
      }
      if (p != temp) {
        //如果没有越过有序链表的第一个节点，说明这个新节点将成为新的首节点
        if (!flag) {
          order_head->next = p;
        }
        //当待加入元素不再大于链表中进行比较的元素，即找到p需要插入的位置
        // p应当插入到temp之前
        pre_p->next = p->next;  // p前面的指针下一个待加入的节点
        pre_temp->next = p;  // p取代temp的位置，pre的next指针指向p
        p->next = temp;      // temp变成p的后继
        p = pre_p->next;     // p再指回新一个待加入节点
      } else {
        //如果p==temp，说明比到了自己，p所处的位置就是正确的位置
        // p后移即可
        pre_p = p;
        p = p->next;
      }
      delete pre_tempoint;
    }
    delete pre_point;
    return order_head->next;
  }
  void test() {
    auto node1 = new ListNode(4);
    auto node2 = new ListNode(2);
    node1->next = node2;
    auto node3 = new ListNode(1);
    node2->next = node3;
    auto node4 = new ListNode(3);
    node3->next = node4;
    auto h = insertionSortList(node1);
  }
};
class Solution_147_back {
 public:
  ListNode *insertionSortList(ListNode *head) {
    //定义一个节点，其值为最小的整数
    //因为是最小的整数，所以必然会在有序链表的第一个
    ListNode dummy(INT32_MIN);  // dummy.next = head;
    ListNode *cur = head;
    //当没有走到链表结尾时循环
    while (cur) {
      //比cur节点值大的前驱节点pos
      // cur->new
      // dummy ...... pos |cur| larger ...... new
      // cur应插入到pos之后
      auto pos = findInsertPos(&dummy, cur->val);
      ListNode *tmp = cur->next;  //记录下一个待排序的节点new
      cur->next = pos->next;  // cur节点的下一个指向pos的下一个 larger
      pos->next = cur;        // pos->cur
      cur = tmp;              // cur重新指向待排序的节点cur=new
    }
    return dummy.next;
  }
  //找出在已head为头节点的链表中，节点值比x大的节点的前驱
  ListNode *findInsertPos(ListNode *head, int x) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    //循环找出一个值大于x的节点，返回这个节点的前驱
    //第一次循环进入循环时 cur为指向INT最小值的节点，必然<=x
    //所以循环必定会进入，返回值pre一定不是nullptr
    while (cur != nullptr && cur->val <= x) {
      pre = cur;
      cur = cur->next;
    }
    return pre;
  }
};
#endif
