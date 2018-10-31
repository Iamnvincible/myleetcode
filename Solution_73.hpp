#ifndef SOLUTION_73
#define SOLUTION_73
/* Given a m x n matrix,
if an element is 0,
set its entire row and column to 0.
Do it in-place.
将矩阵中存在0的每行每列元素都置为0
方法一：需要m+n额外空间，表示行列中存在0的行号、列号
用一个set确保不会重复
遍历一遍确定存在0的行和列
再遍历集合赋0值

方法二：只需要固定大小的额外空间O(1),表示第一行、第一列是否存在0
而后用第一行、第一列的元素来记录每个元素对应的列、行有没有0
如果有，把第一行、第一列对应位置的元素置0
遍历完成后，根据第一行、第一列信息，分别把对应列、行的所有元素置0
要注意跳过第一行、第一列本身，否则列置0完成后可能会影响行，
例如，[0,0]位置为0，这个0可能是1.本身位置为0，2.第一行后面位置为0，3.第一列下方位置为0
第一行、第一列的置0要根据最前面的记录值确定
 */
#include <algorithm>
#include <set>
#include <vector>
class Solution_73 {
 public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::set<int> row, col;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          row.insert(i);
          col.insert(j);
        }
      }
    }
    for (auto i = row.begin(); i != row.end(); i++) {
      std::fill(matrix[*i].begin(), matrix[*i].end(), 0);
    }
    for (auto i = col.begin(); i != col.end(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        matrix[j][*i] = 0;
      }
    }
  }
};
class Solution_73_bak {
 public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    bool row, col;
    row = col = false;
    // check whether the first row contains a zero
    for (auto i : matrix[0]) {
      if (i == 0) {
        row = true;
        break;
      }
    }
    // check first column
    for (int i = 0; i < matrix.size() && matrix[i].size() > 0; i++) {
      if (matrix[i][0] == 0) {
        col = true;
        break;
      }
    }
    // set coordinate place of first row and column to zero if it meets a zero
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    // set zeros by col except first col
    for (int i = 1; i < matrix[0].size(); i++) {
      if (matrix[0][i] == 0) {
        for (int j = 0; j < matrix.size(); j++) {
          matrix[j][i] = 0;
        }
      }
    }
    // set zeros by row except first row
    for (int i = 1; i < matrix.size(); i++) {
      if (matrix[i][0] == 0) {
        std::fill(matrix[i].begin() + 1, matrix[i].end(), 0);
      }
    }
    if (row) {
      std::fill(matrix[0].begin(), matrix[0].end(), 0);
    }
    if (col) {
      for (int j = 0; j < matrix.size(); j++) {
        matrix[j][0] = 0;
      }
    }
  }
};
#endif