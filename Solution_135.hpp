#ifndef SOLUTION_135
#define SOLUTION_135
/* There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
给小孩分糖，分高的小孩要比旁边的小孩多，每个小孩至少一颗
从左到右，如果比左边高，+1
从右到左，如果比右边高，取本身和右边+1的较大值
求和
*/
#include <numeric>
#include <vector>
class Solution_135 {
 public:
  int candy(std::vector<int>& ratings) {
    int size = ratings.size();
    std::vector<int> candy(size, 1);
    for (int i = 1; i < size; i++) {
      if (ratings[i] > ratings[i - 1]) {
        candy[i] = candy[i - 1] + 1;
      }
    }
    for (int i = size - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        candy[i] = std::max(candy[i + 1] + 1, candy[i]);
      }
    }
    return std::accumulate(candy.begin(), candy.end(), 0);
  }
};
#endif