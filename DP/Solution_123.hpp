/*
 * @Author: Jie Lin
 * @Date: 2021-05-09 21:14:45
 * @LastEditTime: 2021-05-09 21:38:55
 * @LastEditors: Jie Lin
 * @Description:Best Time to Buy and Sell Stock III
 * @FilePath: \myleetcode\DP\Solution_123.hpp
 *
 */
#ifndef SOLUTION_123
#define SOLUTION_123
#include <algorithm>
#include <vector>
class Solution_123 {
 public:
  int maxProfit(std::vector<int>& prices) {
    const int size = prices.size();
    if (size < 2) {
      return 0;
    }
    int maxProfit = 0;
    // f数组，f[i]表示在[0,i]范围内，至多交易一次获得的最大利润
    std::vector<int> f(size, 0);
    // g数组，g[i]表示在[i,size)范围内，至多交易一次获得的最大利润
    std::vector<int> g(size, 0);
    for (int i = 1, cheap = prices[0]; i < size; i++) {
      //遍历数组，获得一个最低买入价格
      cheap = std::min(cheap, prices[i]);
      //每遇到一个价格，计算在这个价格下交易获得的利润
      //比较第i天交易获得的利润和前i-1天的获得利润的最大值
      f[i] = std::max(f[i - 1], prices[i] - cheap);
    }
    //从右向左遍历
    for (int i = size - 1, high = prices[size - 1]; i >= 0; i--) {
      // high为记录的最高交易价格
      high = std::max(high, prices[i]);
      //每遇到一个价格，计算在这个价格下买入，在high价格下卖出获得的最大利润
      g[i] = std::max(g[i], high - prices[i]);
    }
    // f[i]+g[i]表示：在前i天内获得的最大利润和在剩余时间内获得最大利润的和
    //整个范围内，至多交易两次获得的最大利润就是f[i]+g[i]在不同i值下和的最大值
    for (int i = 0; i < size; i++) {
      maxProfit = std::max(maxProfit, f[i] + g[i]);
    }
    return maxProfit;
  }
};
#endif