/*
 * @Author: Jie Lin
 * @Date: 2021-04-27 21:18:46
 * @LastEditTime: 2021-04-27 22:03:22
 * @LastEditors: Jie Lin
 * @Description:Best Time to Buy and Sell Stock II
 * @FilePath: \myleetcode\Gready\Solution_122.hpp
 *
 */
#ifndef SOLUTION_122
#define SOLUTION_122
#include <vector>
/**
 * @brief
[7,1,5,3,6,4]
[1,2,3,4,5]
[7,6,4,3,1]
 * @note
 * @retval None
 */
class Solution_122 {
 public:
  int maxProfit(std::vector<int>& prices) {
    int profit = 0;
    int buy = prices[0];
    int sell = prices[0];
    for (size_t i = 1; i < prices.size(); i++) {
      int price = prices[i];
      //如果当前价格大于买入价，即可卖出
      //如果当前价格小于买入价，说明可以在前一个价格下卖出
      if (price > sell || price < buy) {
        sell = price;
        int preProfit = sell - buy;  //计算差价
        if (preProfit > 0) {
          profit += preProfit;
        }
        //卖出同时可以买入
        buy = sell = price;
      }
    }
    return profit;
  }
};
/**
 * @brief  差分法
 * @note   比较直接，记录所有差价，为正加入获利
 * @retval None
 */
class Solution_122_2 {
 public:
  int maxProfit(std::vector<int>& prices) {
    int sum = 0;
    for (int i = 1; i < prices.size(); i++) {
      int diff = prices[i] - prices[i - 1];
      if (diff > 0) sum += diff;
    }
    return sum;
  }
};
#endif
