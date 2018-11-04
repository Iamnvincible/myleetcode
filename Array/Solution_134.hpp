#ifndef SOLUTION_134
#define SOLUTION_134
/* There are N gas stations along a circular route,
 where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and
it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index
if you can travel around the circuit once in the clockwise direction,
otherwise return -1.
Note:
If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
车站加油能否回到起点
O(n^2)的解法，对每个车站循环，看是否能回来
O(n)的解法，考虑整体有没有解，把所有车站加起来看是否<0,
同时记录过程中和不<0的起点
 */
#include <vector>
class Solution_134 {
 public:
  int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int total = gas.size();
    std::vector<int> val(total);
    for (int i = 0; i < total; i++) {
      val[i] = gas[i] - cost[i];
    }
    for (int i = 0; i < total; i++) {
      if (val[i] < 0)
        continue;
      else {
        int left = val[i];
        int loop = 1;
        while (left > 0 && loop < total) {
          left += val[(i + loop) % total];
          loop++;
        }
        if (left >= 0 && loop == total) {
          return i;
        }
      }
    }
    return -1;
  }
};
class Solution_134 {
 public:
  int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int size = gas.size();
    int total = 0;
    int sum = 0;
    int j = 0;
    for (int i = j; i < size; i++) {
      sum += gas[i] - cost[i];
      total += gas[i] - cost[i];
      if (sum < 0) {
        sum = 0;
        j = i + 1;
      }
    }
    if (total >= 0) {
      return j;
    }
    return -1;
  }
};
#endif