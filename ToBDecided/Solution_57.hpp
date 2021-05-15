/*
 * @Author: Jie Lin
 * @Date: 2021-05-14 22:32:53
 * @LastEditTime: 2021-05-15 19:45:47
 * @LastEditors: Jie Lin
 * @Description:Insert Interval
 * @FilePath: \myleetcode\ToBDecided\Solution_57.hpp
 *
 */
#ifndef SOLUTION_57
#define SOLUTION_57
#include <algorithm>
#include <vector>
/**
 * @brief  在一系列区间中插入新的区间，必要时合并区间
 * @note
 * @retval None
 */
class Solution_57 {
 public:
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
#endif