/*
 * @Author: Jie Lin
 * @Date: 2021-04-25 21:13:37
 * @LastEditTime: 2021-04-25 21:45:25
 * @LastEditors: Jie Lin
 * @Description:Jump Game II
 * @FilePath: \myleetcode\Gready\Solution_45.hpp
 *
 */
#ifndef SOLUTION_45
#define SOLUTION_45
#include <vector>
/**
 * @brief
 * 跳跃游戏2
 * 给出一个数组，初始位置位于0，位置对应数组值表示在当前位置可以往数组结尾跳跃的最大偏移
 * 这次要找到能够跳到最后位置的最少跳数，给出的数组一定能跳到最后
 * @note
 * @retval None
 */
class Solution_45 {
 public:
  int jump(std::vector<int>& nums) {
    int res = 0;  //最少跳跃步数
    int size = nums.size();
    int i = 0, cur = 0;  // i为当前位置，cur表示当前能跳到得最远位置
    //当前位置还未到大数组结尾时继续尝试
    while (cur < size - 1) {
      ++res;
      int pre = cur;  //在尝试这一步之前能到达的最远位置
      //内循环，寻找在达到位置pre前，能够以最少步数到达的最远位置
      while (i <= pre) {
        //如果在当前位置采取最大跳跃
        int attempt = i + nums[i];
        //取当前跳跃和历史最远位置之间的最大值
        cur = cur > attempt ? cur : attempt;
        //继续尝试下一个位置
        i++;
      }
      //当尝试到cur位置仍然不能往前走，说明不能到达最后，跳跃失败
      //   if (cur == pre) return -1;
    }
    return res;
  }
};
#endif