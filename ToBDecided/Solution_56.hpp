/*
 * @Author: Jie Lin
 * @Date: 2021-05-15 20:03:30
 * @LastEditTime: 2021-05-15 20:43:30
 * @LastEditors: Jie Lin
 * @Description:Merge Intervals
 * @FilePath: \myleetcode\ToBDecided\Solution_56.hpp
 *
 */
#ifndef SOLUTION_56
#define SOLUTION_56
#include <algorithm>
#include <vector>
/**
 * @brief  合并区间，可以之间复用57的方法
 * @note
 * @retval None
 */
class Solution_56 {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>>& intervals) {
    std::vector<std::vector<int>> res;
    for (int i = 0; i < intervals.size(); i++) {
      res = insert(res, intervals[i]);
    }
    return res;
  }

 private:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
                                       std::vector<int>& newInterval) {
    //返回新的区间序列，不要再原区间上修改
    std::vector<std::vector<int>> res;
    int size = intervals.size();
    int index = 0;
    //先将序列中大端数小于插入新区间小端数字的所有区间加入返回值，这些区间不需要处理
    while (index < size && intervals[index][1] < newInterval[0]) {
      res.push_back(intervals[index++]);
    }
    //做完上一步循环后，当前区间intervals[index][0]>=newInterval[0]
    //下一步循环需要确定newInterval[1]的位置，需要与序列中区间的小端比较
    while (index < size && intervals[index][0] <= newInterval[1]) {
      //每遇到一个满足循环条件的区间，需要合并区间范围
      //合并后的新区间需要满足，小端是较小的值，大端是较大值
      newInterval[0] = std::min(newInterval[0], intervals[index][0]);
      newInterval[1] = std::max(newInterval[1], intervals[index][1]);
      //有需要合并多个区间的情况，所以newInterval[1]的值会更新
      index++;
    }
    //完成上一步循环后，interval[index][0]>newInterval[1]
    //将合并后的区间范围加入返回值
    res.push_back(newInterval);
    //后续区间不需要处理，之间加入返回值
    while (index < size) {
      res.push_back(intervals[index++]);
    }
    return res;
  }
};
/**
 * @brief 给出的区间无序，将区间的小端和大端放入不同数组后再排序
 * 比较小端数组和大端数组的值，完成区间的合并
 * @note
 * @retval None
 */
class Solution_56_2 {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>>& intervals) {
    int size = intervals.size();
    std::vector<std::vector<int>> res;
    std::vector<int> lefts, rights;
    //将区间小端和大端分离，放入不同数组
    for (size_t i = 0; i < size; i++) {
      lefts.push_back(intervals[i][0]);
      rights.push_back(intervals[i][1]);
    }
    //排序
    std::sort(lefts.begin(), lefts.end());
    std::sort(rights.begin(), rights.end());
    //排序后，为了合并区间，需要确保区间连续
    //当前位置为i，如果小端位置i+1的数字大于大端位置i的数字就需要合并
    //合并后确保小端位置i的数字小于大端位置j的数字
    //或者当i走到结尾处，合并left[j],rights[i](大端最后一个)
    // left[0]在题中必然是最小的数字
    // j实际代表小端数组中尚未合并的位置
    for (size_t i = 0, j = 0; i < size; i++) {
      if (i == size - 1 || lefts[i + 1] > rights[i]) {
        res.push_back({lefts[j], rights[i]});
        j = i + 1;
      }
    }
    return res;
  }
};
#endif