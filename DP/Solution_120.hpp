/*
 * @Author: Jie Lin
 * @Date: 2021-04-30 22:37:09
 * @LastEditTime: 2021-05-01 22:49:44
 * @LastEditors: Jie Lin
 * @Description:Triangle
 * @FilePath: \myleetcode\DP\Solution_120.hpp
 *
 */
#ifndef SOLUTION_120
#define SOLUTION_120
#include <algorithm>
#include <iostream>
#include <vector>
/**
 * @brief
 * 给出一个二维数组组成的三角形，数组值为权值，求从顶部到底部的最小权值路径
 * 当前行的一个数字下标为i只能往下一行的的i,i+1位置走
 * @note
 * 方法一：求权值的最小值，可以把所有路径列出来，找其中权值最小的一条路
 * 但是路径有n!那么多，时间会很长
 * @retval None
 */
class Solution_120 {
 public:
  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    int minPath = INT_MAX;
    enumerate(triangle, 1, 0, triangle[0][0], minPath);
    return minPath;
  }

 private:
  void enumerate(std::vector<std::vector<int>>& triangle, int layer,
                 int lastIndex, int path, int& minPath) {
    if (layer == triangle.size()) {
      minPath = std::min(minPath, path);
    } else {
      int left = triangle[layer][lastIndex];
      int right = triangle[layer][lastIndex + 1];
      enumerate(triangle, layer + 1, lastIndex, path + left, minPath);
      enumerate(triangle, layer + 1, lastIndex + 1, path + right, minPath);
    }
  }
};
/**
 * @brief  方法二：动态规划
 * @note   每一行计算到每个位置的最短路径，排除了其他路径，减少计算次数
 * @retval None
 */
class Solution_120_2 {
 public:
  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    // row存放到第几行每个位置的最短路径
    std::vector<int> row(triangle.size());
    //第0行可以直接赋值
    row[0] = triangle[0][0];
    //从第1行开始，遍历每一行
    for (int i = 1; i < triangle.size(); i++) {
      //临时记录到当前行每个位置的最短路径
      std::vector<int> tmp(triangle[i].size());
      //遍历当前行每个位置，并计算到每个位置的最短路径
      for (int j = 0; j < triangle[i].size(); j++) {
        //到当前行位置triangle[i][j]的最短路径为:
        //到上一行triangle[i-1][j-1]和triangle[i-1][j]两者较短一条的权值与当前triangle[i][j]之和
        // tmp[i][j]=triangle[i][j]+min(row[j-1],row[j])
        int left = j == 0 ? INT_MAX : row[j - 1];
        int right = ((j == triangle[i].size() - 1) ? INT_MAX : row[j]);
        //将权值加入tmp
        tmp[j] = std::min(left, right) + triangle[i][j];
      }
      //将tmp替换row，为下一行计算准备
      row.clear();
      for (auto&& i : tmp) {
        row.push_back(i);
      }
    }
    //循环完成后，row保存了到最后一行每个位置的最短路径，求其中的最小值
    return *std::min_element(row.begin(), row.end());
  }
};
/**
 * @brief  将路径倒过来走，不需要判断第一个和最后一个元素的特殊算法
 * @note
 * @retval None
 */
class Solution_120_3 {
 public:
  int minimumTotal(std::vector<std::vector<int>>& triangle) {
    //复制了三角形最后一行
    std::vector<int> dp(triangle.back());
    //从最后一行向上遍历
    for (int i = (int)triangle.size() - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        //当上一行第j个位置的最短路径为
        //当前行j和j+1位置的较小值与上一行j位置权值之和
        //由于dp数组长度为最后一行的长度，向上走时不需要再分配额外空间，重复利用即可
        dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j];
      }
    }
    //循环结束后，dp数组首位就是从下往上走路径最短的值
    return dp[0];
  }
};
#endif