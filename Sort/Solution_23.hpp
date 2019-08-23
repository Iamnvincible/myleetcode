#ifndef SOLUTION_23
#define SOLUTION_23
#include <queue>
#include <vector>
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
//方法一 复用21题思路 依次对两个链表排序
//这样时间复杂度就是n^2
class Solution_23 {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode* head = nullptr;
    if (lists.size()) {
      head = lists[0];
    }
    for (size_t i = 1; i < lists.size(); i++) {
      head = mergeTwoLists(lists[i], head);
    }
    return head;
  }

 private:
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
//方法二 使用优先队列
//优先队列保证出队的元素是按照一个比较规则下最小的（也可以最大）
//因为优先队列插入元素时会排序，对数代价的时间log(n)
//总的复杂度就是nlog(n)
class Solution_23_back {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    auto head = new ListNode(0);
    auto res = head;
    //用lambda比较元素
    auto comp = [](const ListNode* l1, const ListNode* l2) {
      return l1->val > l2->val;
    };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> pq(
        comp);
    for (auto i : lists) {
      if (i) {
        pq.push(i);
      }
    }
    while (!pq.empty()) {
      auto node = pq.top();
      pq.pop();
      head->next = node;
      head = head->next;
      if (node->next) {
        pq.push(node->next);
      }
    }
    return res->next;
  }
};
#endif