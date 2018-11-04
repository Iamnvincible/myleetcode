#ifndef SOLUTION_46
#define SOLUTION_46
/* You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Note:
You have to rotate the image in-place,
which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.
给定一个矩阵，将其顺时针旋转90度，不能再分配一个矩阵空间
朴素的想法，找旋转的规律
从外往里，一个旋转了的正方形的顶点值挨个交换值
简洁的想法
先对向量转置一下，再交换对角线的值就可以了
充分发挥了C++标准库的效力，代码非常简洁
*/
#include <algorithm>
#include <vector>
class Solution_46 {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    int size = matrix.size();
    for (int i = 0; i < size / 2; i++) {
      for (int j = 0; j <= size / 2; j++) {
        //注意偶数的时候相等的情况要排除，否者就多做了一次交换
        if (size % 2 == 0 && j == size / 2) {
          continue;
        }
        int temp = matrix[i][j];
        matrix[i][j] = matrix[size - 1 - j][i];
        matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
        matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
        matrix[j][size - 1 - i] = temp;
      }
    }
  }
};
class Solution_46_bak {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    std::reverse(matrix.begin(), matrix.end());
    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = i; j < matrix.size(); j++) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
#endif