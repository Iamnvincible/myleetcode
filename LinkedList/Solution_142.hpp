#ifndef SOLUTION_142
#define SOLUTION_142
/* Given a linked list,
return the node where the cycle begins.
If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
给出一个可能存在环的链表
找出环的起始位置（靠前的起始位置）
如不存在环，返回NULL

第一种方法会超时
从第一个节点开始逐个判断，
判断这个节点的指针有没有在后面循环中出现
为了防止循环在后面跳不出来
还有判断后面是否成环，方法同141题

第二种方法非常巧妙
从141题的思路，设置一个fast，slow指针
遍历中找到其相遇的位置，判断是否有环到这里就完成了
为了找到环开始的地方
假设环起始节点距离链表头n个单位
fast和slow相遇的位置距离链表头n+k个单位
环中共有m个节点
那么到相遇点时
slow走了n+k个单位
fast走了2(n+k)=n+k+cm个单位，c为fast在环中走了c圈，c>=1
那么n+k=cm，
我们要求n，n=cm-k=(c-1)m+m-k;
slow再走m-k+cm个单位就会再次抵达环的起始位置
那么如果有另外一个指针从链表头部往后走n步，也能走到环起始位置
即这两个指针相遇的位置就是环起始位置

*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution_142 {
 public:
  ListNode *detectCycle(ListNode *head) {
    auto ptr = head, cur = head;
    while (ptr) {
      auto slow = ptr;
      while (cur && cur->next) {
        cur = cur->next->next;
        slow = slow->next;
        if (ptr == slow) {
          return slow;
        }
        if (cur == slow) {
          break;
        }
      }
      ptr = ptr->next;
      cur = ptr;
    }
    return nullptr;
  }
};
class Solution_142_bak {
 public:
  ListNode *detectCycle(ListNode *head) {
    auto fast = head, slow = head, slow2 = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        //找到相遇点
        //设循环起始位置距离head为n步，slow和fast相遇在距离n有k步的位置，整个循环有m步；
        // slow再往前走m-k或m-k+cm步到达循环的起始位置，c为自然数
        // slow2往前走n步 n=m-k+cm
        // slow2和slow相遇在循环起始位置
        //两个指针相遇的位置就是循环起始位置
        while (slow2 != slow) {
          slow2 = slow2->next;
          slow = slow->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
#endif