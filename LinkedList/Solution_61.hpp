#ifndef SOLUTION_61
#define SOLUTION_61
/* Given a linked list,
rotate the list to the right by k places,
where k is non-negative.
从链表尾部依次取k个元素一定到头部，k可能大于链表长度
先遍历一遍获得链表长度，并使其首尾相连
把k对长度取余，
再从头遍历
遍历到还有k-1个元素的时候出来
返回后k个元素的头部，
再把环断掉
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution_61 {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !k) return head;//特殊情况处理
    auto orihead = head;
    int size = 0;
    while (head->next) {
      size++;
      head = head->next;
    }
    size++;
    head->next = orihead;//首尾相连
    k = size - k % size;
    head = orihead;
    int count = 1;
    while (count != k) {//遍历到目标节点的前一个
      head = head->next;
      count++;
    }
    auto res = head->next;
    head->next = nullptr;
    return res;
  }
};
#endif