/*
 * @Author: Jie Lin
 * @Date: 2021-04-26 21:38:12
 * @LastEditTime: 2021-04-26 22:01:50
 * @LastEditors: Jie Lin
 * @Description:Best Time to Buy and Sell Stock
 * @FilePath: \myleetcode\Gready\Solution_121.hpp
 *
 */
#ifndef SOLUTION_121
#define SOLUTION_121
#include <vector>
/**
 * @brief  给出几天的股票价格，计算出在这几天里交易可以获得的最大利润
 * @note 不需要记录具体哪一天买入、卖出，只需要记录最大的利润
 * @retval None
 */
class Solution_121 {
 public:
  int maxProfit(std::vector<int>& prices) {
    if (prices.size() == 0) {
      return 0;
    }
    //假设第0天买入
    int buy = prices[0];
    //当前利润（差价），获利必须为正
    int offset = 0;
    for (size_t i = 0; i < prices.size(); i++) {
      //找出价格最低的一天买入
      //第i天价格比之前买入价格低，那么应该在这一天买入
      //不需要记录具体在哪一天买入、卖出，只需要记录最大的差价
      if (prices[i] <= buy) {
        buy = prices[i];
      } else {
        //如果第i天价格比买入价格高，计算在这一天卖出获得的差价
        int value = prices[i] - buy;
        //如果差价比之前的差价更高，这个差价作为当前最大差价
        if (value > offset) {
          offset = value;
        }
      }
    }
    return offset;
  }
};
#endif