/*
 * @Author: Jie Lin
 * @Date: 2021-05-08 23:07:15
 * @LastEditTime: 2021-05-08 23:52:33
 * @LastEditors: Jie Lin
 * @Description:Maximal Rectangle
 * @FilePath: \myleetcode\DP\Solution_85.hpp
 *
 */
#ifndef SOLUTION_85
#define SOLUTION_85
#include <algorithm>
#include <stack>
#include <vector>
class Solution_85 {
 public:
  int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    int largest = 0;
    std::vector<int> height;
    for (int i = 0; i < matrix.size(); i++) {
      height.resize(matrix[i].size());
      for (int j = 0; j < matrix[i].size(); j++) {
        height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
      }
      largest = std::max(largest, largestRectangleArea(height));
    }
    return largest;
  }

 private:
  int largestRectangleArea(std::vector<int>& heights) {
    int largest = 0;
    std::stack<int> s;
    heights.push_back(0);
    int index = 0;
    while (index < heights.size()) {
      if (s.empty() || heights[index] > heights[s.top()]) {
        s.push(index++);
      } else {
        int heigh = s.top();
        s.pop();
        if (s.empty()) {
          largest = std::max(largest, index * heights[heigh]);
        } else {
          largest = std::max(largest, (index - s.top() - 1) * heights[heigh]);
        }
      }
    }
    return largest;
  }
};
#endif