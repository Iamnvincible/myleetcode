#ifndef SOLUTION_611
#define SOLUTION_611
#include <algorithm>
#include <vector>
/*
611. Valid Triangle Number
Given an integer array nums,
return the number of triplets chosen from the array
that can make triangles
if we take them as side lengths of a triangle.
*/
class Solution_611 {
public:
  int triangleNumber(std::vector<int> &nums) {
    int result = 0;
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size - 2; i++) {
      int x = nums[i];
      if (x == 0) {
        continue;
      }
      int j = i + 1;
      for (int k = i + 2; k < size; k++) {
        while (nums[k] - nums[j] >= x) {
          j++;
        }
        result += k - j;
      }
    }
    return result;
  }
};

class Solution_611_1 {
public:
  int triangleNumber(std::vector<int> &nums) {
    int result = 0;
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size - 2; i++) {
      int x = nums[i];
      if (x == 0) {
        continue;
      }
      /* approach 1*/
      int j = size - 2;
      for (int k = size - 1; k > i + 1; k--) {
        j = std::min(k - 1, j);
        while (j > i) {
          if (x + nums[j] <= nums[k]) {
            break;
          } else {
            j--;
          }
        }
        result += (k - j - 1);
      }
      /* appraoch 2 */
      // int last_k = i + 2;
      // for (int j = i + 1; j < size - 1; j++) {
      //   int k = last_k;
      //   int two_sides = x + nums[j];
      //   while (k < size && two_sides > nums[k]) {
      //     k++;
      //   }
      //   result += (k - j - 1);
      //   last_k = k - 1;
      // }
    }
    return result;
  }
};
class Solution_611_2 {
public:
  int triangleNumber(std::vector<int> &nums) {
    int result = 0;
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int k = size - 1; k > 1; k--) {
      if (nums[0] + nums[1] > nums[k]) { // 优化一
        result += (k + 1) * k * (k - 1) / 6;
        break;
      }
      if (nums[k - 2] + nums[k - 1] <= nums[k]) { // 优化二
        continue;
      }
      int i = 0;
      int j = k - 1;
      while (i < j) {
        if (nums[i] + nums[j] > nums[k]) {
          result += (j - i);
          j--;
        } else {
          i++;
        }
      }
    }
    return result;
  }
};
/*双指针解法
比较 Solution_167 two sum 的双指针解法。
内层循环是两个逐渐从两边靠近的指针，这是双指针的特点。
内层循环结束条件是指针相遇、错过。
由于操作的数组是有序的，可以在一次遍历时通过有序这个强特征完成筛选的功能。这也是一个特点。
也因为有序，可以在循环时处理特殊情况，跳过不必要的循环。
两个指针指向的对象需要与另一个值满足某种数量关系。
当这两个指针靠近时，这个目标数值不会变化。
这点在双指针之上还有外层循环时需要注意。外层循环可以作为目标数值不变化的循环对象。
最后要注意的是两个指针在什么条件下靠近。靠近不能产生重复的比较。依据具体条件判定。
有序条件可以在循环时减少靠近次数。

本题三边构成三角形，条件是任意两边之和大于第三边。
将条件特殊化后，变成两个短边之和大于第三边。
a<=b<=c, a+b>c
有序条件很好满足了找两个短边，那么固定长边作为外层循环即可。
那么外层循环就要从最大值开始往更小的方向循环。
内层循环要让两个指针靠近，分别是最小和最大的数，开始靠近。
靠近条件：两边之和大于第三边，当最短的边加上一个边大于最长边条件满足时，
比最短边长且小于等于第二长边的所有边长都能和第二长边构成大于第三边的条件。
因此，在这之间的元素个数就是可能的边长组合。
此后，要尝试减小第二长边长，增加最短边长，继续尝试。直到两指针相遇。

*/

class Solution_611_2_1 {
public:
  int triangleNumber(std::vector<int> &nums) {
    int result = 0;
    int size = nums.size();
    std::sort(nums.begin(), nums.end());
    for (int k = size - 1; k > 1; k--) {
      int i = 0;
      int j = k - 1;
      int longest = nums[k];
      if (longest >= nums[k - 1] + nums[k - 2])
        continue;
      if (longest < nums[0] + nums[i]) {
        // select 2 from k elements
        // result += (k - 1) * k / 2;
        // continue;
        //
        // or
        // select 3 from k+1 elements
        result += (k + 1) * k * (k - 1) / 6;
        break;
      }
      while (i < j) {
        int two_sides = nums[i] + nums[j];
        if (two_sides > longest) {
          result += (j - i);
          j--;
        } else {
          do {
            i++;
          } while (nums[i] == 0);
        }
      }
    }
    return result;
  }
};
#endif
// 2,2,3,4

// 2,3,4
// 2,3,4
// 2,2,3