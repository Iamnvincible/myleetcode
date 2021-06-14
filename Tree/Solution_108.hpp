/*
 * @Author: Jie Lin
 * @Date: 2021-06-14 21:39:33
 * @LastEditTime: 2021-06-14 22:17:59
 * @LastEditors: Jie Lin
 * @Description:Convert Sorted Array to Binary Search Tree
 * @FilePath: \myleetcode\Tree\Solution_108.hpp
 *
 */
#ifndef SOLUTION_108
#define SOLUTION_108
#include <vector>

#include "TreeNode.h"
class Solution_108 {
 public:
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    int size = nums.size();
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