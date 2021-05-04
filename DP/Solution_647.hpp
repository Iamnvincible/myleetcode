/*
 * @Author: Jie Lin
 * @Date: 2021-05-03 17:15:51
 * @LastEditTime: 2021-05-04 22:37:48
 * @LastEditors: Jie Lin
 * @Description:Palindromic Substrings
 * @FilePath: \myleetcode\DP\Solution_647.hpp
 *
 */
#ifndef SOLUTION_647
#define SOLUTION_647
#include <string>
#include <vector>
/**
 * @brief  给出一个字符串，找出所有是回文字符串的子字符串总数
 * @note
 * 穷举所有长度的字符串判断，挑出不是回文字符串的，所有子字符串数量减去不是回文的就是结果
 * @retval None
 */
class Solution_647 {
 public:
  int countSubstrings(std::string s) {
    int res = 0;
    //从第一个字符开始，穷举所有长度的字符串，检验是否是回文字符串
    // i,j分别是子字符串的左右两端
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        for (int k = i, l = j; k < l; k++, l--) {
          if (s[k] != s[l]) {
            res--;
            break;
          }
        }
      }
    }
    //所有子字符串的个数n+ n-1 + n-2 + ... + 1
    int tri = (1 + s.size()) * s.size() / 2;
    res += tri;
    return res;
  }
};
/**
 * @brief  动态规划求解
 * @note 定义动态规划数组,这里是二维数组matrix,代表一个矩阵
 * 矩阵元素matrix[i][j]表示字符串i-j之间的子字符串是否是回文字符串
 *    a0 a1 a2
 * a0 T  ?  ?
 * a1 ?  T  ?
 * a2 ?  ?  T
 * 可以只关注矩阵的右上部分的? i<=j
 * 显然，矩阵中对角线元素均为True，因为单个元素认为是回文字符串
 * 为求matrix[i][j]代表的子字符串是否是回文字符串，
 * 只要
 * 1. 比较s[i]-s[j]两端是否字符相同，s[i]==s[j]。
 * 2. 借助动态规划数组matrix，两端比较完成后，
 *    只需要知道s[i+1]-s[j-1]这个子字符串是否是回文字符串，
 *    即取matrix[i+1][j-1]这个元素的值与上一步求得的值相'与'即可
 *    状态转移条件：matrix[i][j] = (s[i]==s[j] && matrix[i+1][j-1])
 * 3. 注意，i,j之间如果只有0、1个字符时不需要 matrix[i+1][j-1]
 * 4. 由于计算matrix[i][j]时需要先知道matrix[i+1][j-1](情况3除外)，
 *    所以需要注意计算矩阵值的顺序
 * @retval None
 */
class Solution_647_2 {
 public:
  int countSubstrings(std::string s) {
    std::vector<std::vector<bool>> matrix{s.size(),
                                          std::vector<bool>(s.size())};
    int res = 0;  //保存回文字符串数量
    //字符串左端下标从下标较大处递减循环
    for (int i = s.size() - 1; i >= 0; i--) {
      //从对角线开始计算
      for (int j = i; j < s.size(); j++) {
        if (j - i >= 2) {
          matrix[i][j] = s[i] == s[j] && matrix[i + 1][j - 1];
        } else {
          matrix[i][j] = s[i] == s[j];
        }
        if (matrix[i][j]) ++res;
      }
    }
    return res;
  }
};
//正序来求matrix
// 0,0
// 0,1 1,1
// 0,2 1,2 2,2
//...
class Solution_647_3 {
 public:
  int countSubstrings(std::string s) {
    std::vector<std::vector<bool>> matrix{s.size(),
                                          std::vector<bool>(s.size())};
    int res = 0;  //保存回文字符串数量
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j <= i; j++) {
        if (i - j >= 2) {
          matrix[j][i] = s[i] == s[j] && matrix[j + 1][i - 1];
        } else {
          matrix[j][i] = s[i] == s[j];
        }
        if (matrix[j][i]) ++res;
      }
    }
    return res;
  }
};
#endif