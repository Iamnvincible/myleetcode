#ifndef SOLUTION_2105
#define SOLUTION_2105
/*
爱丽丝和鲍勃给花园里的植物浇水。
植物共 n 盆，从 0 到 n-1 排列为一行。
每盆植物需要浇特定数量的水。两人分别有一个水壶，开始打满水。
- 爱丽丝从左往右浇水，从 0 开始。鲍勃从右往左浇水，从 n-1 开始。两人同步开始。
- 浇一盆植物所用时间相同
- 浇一盆植物前检查水壶剩余水量，不足以浇一盆植物时先打满再浇（打水时间忽略）
- 要是两人来到同一盆植物，水多的一人来浇，如果相同，爱丽丝来浇
- 水壶容量大于任何一盆植物需要的水量

数组 plants[n]，数值代表需要浇水的量。
capaciA capaciB 表示爱丽丝和鲍勃的水壶容量。
计算这个任务结束后，两人需要打满水的次数。

相向双指针做法
初始化各自水壶水量为最大容量
双指针遍历数组
在两人相遇前，各自浇水，记录剩余水量变化
如果水不够，打水次数自增，剩余水量加满
浇水完成，双指针各自增减

如果两人相遇，取剩余水量多的于植物需要水量比较，不够则增加打水次数
*/
#include <vector>
class Solution_2105 {
 public:
  int minimumRefill(std::vector<int>& plants, int capacityA, int capacityB) {
    int res = 0;
    int left = 0, right = plants.size() - 1;
    int leftA = capacityA, leftB = capacityB;
    while (left < right) {
      int pl = plants[left];
      int pr = plants[right];
      if (leftA < pl) {
        res++;
        leftA = capacityA;
      }
      leftA -= pl;

      if (leftB < pr) {
        res++;
        leftB = capacityB;
      }
      leftB -= pr;
      left++;
      right--;
    }
    if (left == right) {
      int max = leftA >= leftB ? leftA : leftB;
      if (max < plants[left]) {
        res++;
      }
    }
    return res;
  }
};

#endif