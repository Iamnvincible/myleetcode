/*
 * @Author: Jie Lin
 * @Date: 2021-06-17 22:27:22
 * @LastEditTime: 2021-06-17 22:29:57
 * @LastEditors: Jie Lin
 * @Description:Convert Sorted List to Binary Search Tree
 * @FilePath: \myleetcode\Tree\Solution_109.hpp
 *
 */
#ifndef SOLUTION_109
#define SOLUTION_109
#include <vector>

#include "../LinkedList/ListNode.h"
#include "TreeNode.h"
/**
 * @brief  将有序链表转化为平衡二叉搜索树，只要在108题上加一点就可以了
 * @note
 * @retval None
 */
class Solution_109 {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    std::vector<int> nums;
    while (head) {
      nums.push_back(head->val);
      head = head->next;
    }
    int size = nums.size();
    if (size == 0) return NULL;
    TreeNode* root = new TreeNode(-1);
    binarySearch(nums, root, 0, size - 1);
    return root;
  }

 private:
  void binarySearch(std::vector<int>& nums, TreeNode* root, int left,
                    int right) {
    if (left <= right) {
      int mid = left + (right - left) / 2;
      root->val = nums[mid];
      if (left <= mid - 1) {
        TreeNode* leftNode = new TreeNode(-1);
        root->left = leftNode;
        binarySearch(nums, leftNode, left, mid - 1);
      }
      if (mid + 1 <= right) {
        TreeNode* rightNode = new TreeNode(-1);
        root->right = rightNode;
        binarySearch(nums, rightNode, mid + 1, right);
      }
    }
  }
};
#endif