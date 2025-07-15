#ifndef SOLUTION_42
#define SOLUTION_42
/*
Given n non-negative integers representing an elevation map
where the width of each bar is 1,
compute how much water it is able to trap after raining.
给出一个像俄罗斯方块一样的方块高度序列，计算里面能积水的体积
我naive的想法是一层一层算，就比较费时间
advanced的想法是找出里面最高的高度，
分别从左从右向这个最高开始遍历，
左边，因为右边有最高的撑着，只要比前一个低，低的差距就能积到水；右边也是一样道理
 */
#include <vector>
class Solution_42 {
 public:
  int trap(std::vector<int> &height) {
    if (height.size() <= 1) {
      return 0;
    }
    int L = 0;
    int R = height.size() - 1;
    int sub = 0;
    int count = 0;
    while (true) {
      while (height[L] <= sub) {
        L++;
      }
      while ((height[R]) <= sub) {
        R--;
      }
      if (L >= R) {
        break;
      } else {
        for (int i = L; i < R; i++) {
          if (height[i] <= sub) {
            count++;
          }
        }
      }
      sub++;
    }
    return count;
  }
};
class Solution_42_bak {
 public:
  int trap(std::vector<int> &height) {
    int max = 0;
    int count = 0;
    if (height.size() <= 1) {
      return 0;
    }
    for (int i = 0; i < height.size(); i++) {
      max = height[i] > height[max] ? i : max;
    }
    int temphigh = 0;
    for (int i = 0; i < max; i++) {
      if (temphigh <= height[i]) {
        temphigh = height[i];
      } else {
        count += (temphigh - height[i]);
      }
    }
    temphigh = 0;
    // 在递减时要注意循环变量最好不要用size_t
    for (int i = height.size() - 1; i > max; i--) {
      if (temphigh <= height[i]) {
        temphigh = height[i];
      } else {
        count += (temphigh - height[i]);
      }
    }
    return count;
  }
};
/*
柱子高度最低为 0.
取左右各一根柱子，中间相隔若干根柱子。
两根柱子之间能够储水意味着这两个柱子之间的柱子中有比这两根柱子更低的柱子。
如果右边的柱子相对左边柱子更高，
那么左边柱子到右边柱子之间，只要有比左边柱子低的柱子，就能在这些较低柱子处储水。

双指针方法，从两边向内侧统计储水总量。
左右两侧预设的最高高度为 0.
先获得左右两侧高度，获得的两个高度分别与已知的左右两侧最大高度比较，更新两侧最大高度。
如果右侧的最大高度更高，那么左侧就可以储水。
  （只要左侧的柱子高度比左边最大高度低，相同时储水为 0，不影响逻辑）
  即便这个位置右边可能存在更高的柱子，但这个位置储水量只与其左边所有柱子高度最大值有关，
  右边无论有多高的柱子都不能使这个位置多储水，这是短板原理。
  这个位置储水量就是（左边最高柱子高度-这个位置柱子高度）*（长度 = 1）
  这个位置计算过之后就可以往里走。继续统计
如果左侧的最大高度更高，那么右侧就可以储水。
直到左右相遇结束统计。
*/
class Solution_42_2 {
 public:
  int trap(std::vector<int> &height) {
    int i = 0, j = height.size() - 1;
    int result = 0;
    int left_most = 0;
    int right_most = 0;
    while (i < j) {
      int left = height[i];
      int right = height[j];
      left_most = std::max(left_most, left);
      right_most = std::max(right_most, right);
      int vol = 0;
      if (left_most > right_most) {
        vol = right_most - right;
        j--;
      } else {
        vol = left_most - left;
        i++;
      }
      result += vol;
    }
    return result;
  }
};
#endif