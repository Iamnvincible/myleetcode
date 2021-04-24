/*
 * @Author: Jie Lin
 * @Date: 2021-04-24 19:27:21
 * @LastEditTime: 2021-04-24 19:51:50
 * @LastEditors: Jie Lin
 * @Description:Jump Game
 * @FilePath: \myleetcode\Gready\Solution_55.hpp
 *
 */
#ifndef SOLUTION_55
#define SOLUTION_55
/**
 * @brief
 * 跳跃游戏，给出一个数组，初始位置位于0，位置对应数组值表示在当前位置可以往数组结尾跳跃的最大偏移
 * 判断给出的数组能否按上面的规则跳到数组最后（或超过最后一个）的位置
 * @note
 * @retval None
 */
#include <vector>
class Solution_55 {
 public:
  bool canJump(std::vector<int>& nums) {
    int reach = 0;  //表示当前能达到的最远位置
    int size = nums.size();
    int target = size - 1;
    //遍历数组，查看每个位置能跳几步
    //对比能达到的最远位置，选一个更大的
    //不断更新reach
    for (size_t i = 0; i < size; i++) {
      //如果i>reach,说明在到达i位置之前，不能从之前的跳跃中到达i，也就不能往后走，跳跃失败，退出
      //如果当前坐标已经到达最后一个位置，跳跃成功，跳出循环
      if (i > reach || reach >= target) break;
      //比较已经能到达的最远位置和当前循环所在位置能达到的最远位置
      //选一个较大的
      reach = reach > (i + nums[i]) ? reach : (i + nums[i]);
    }
    return reach >= target;
  }
};
#endif