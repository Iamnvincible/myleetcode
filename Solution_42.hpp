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
class Solution_42
{
  public:
    int trap(std::vector<int> &height)
    {
        if (height.size() <= 1)
        {
            return 0;
        }
        int L = 0;
        int R = height.size() - 1;
        int sub = 0;
        int count = 0;
        while (true)
        {
            while (height[L] <= sub)
            {
                L++;
            }
            while ((height[R]) <= sub)
            {
                R--;
            }
            if (L >= R)
            {
                break;
            }
            else
            {
                for (int i = L; i < R; i++)
                {
                    if (height[i] <= sub)
                    {
                        count++;
                    }
                }
            }
            sub++;
        }
        return count;
    }
};
class Solution_42_bak
{
  public:
    int trap(std::vector<int> &height)
    {
        int max = 0;
        int count = 0;
        if (height.size() <= 1)
        {
            return 0;
        }
        for (int i = 0; i < height.size(); i++)
        {
            max = height[i] > height[max] ? i : max;
        }
        int temphigh = 0;
        for (int i = 0; i < max; i++)
        {
            if (temphigh <= height[i])
            {
                temphigh = height[i];
            }
            else
            {
                count += (temphigh - height[i]);
            }
        }
        temphigh = 0;
        //在递减时要注意循环变量最好不要用size_t
        for (int i = height.size() - 1; i > max; i--)
        {
            if (temphigh <= height[i])
            {
                temphigh = height[i];
            }
            else
            {
                count += (temphigh - height[i]);
            }
        }
        return count;
    }
};
#endif