#ifndef SOLUTION_128
#define SOLUTION_128
/*
 *Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *Your algorithm should run in O(n) complexity.
 *使用unorered_map记录出现过的元素为false
 *为统计连续序列，在循环中左右尝试寻找连续元素
 *找到的元素记录为true，同时为后续尝试节省时间，否则会在最后几个测试用例中超时
 *并且一个子序列中只要尝试找过一个元素，其他子序列就不必再尝试，很巧妙
*/
#include <unordered_map>
#include <vector>
class Solution_128
{
  public:
    int longestConsecutive(std::vector<int> &nums)
    {
        std::unordered_map<int, bool> used;
        for (int i = 0; i < nums.size(); i++)
        {
            used[nums[i]] = false;
        }
        int longest = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[nums[i]])
                continue;
            int length = 1;
            used[nums[i]] = true;
            int j = nums[i];
            while (used.find(++j) != used.end())
            {
                length++;
                used[j] = true;
            }
            j = nums[i];
            while (used.find(--j) != used.end())
            {
                length++;
                used[j] = true;
            }
            longest = std::max(longest, length);
        }
        return longest;
    }
    int test()
    {
        std::vector<int> nums = {100, 4, 200, 1, 3, 2};
        int res = longestConsecutive(nums);
    }
};
/*
 *另解
 *连续序列长度用两端来表示
*/
class Solution_128_bak
{
  public:
    int longestConsecutive(std::vector<int> &nums)
    {
        std::unordered_map<int, int> map;
        int size = nums.size();
        int l = 1;
        for (int i = 0; i < size; i++)
        {
            //如果map中找不到当前元素键，继续向下执行，找到就开始下一轮循环
            if (map.find(nums[i]) != map.end())
                continue;
            //记录为1
            map[nums[i]] = 1;
            //左右寻找，存在键继续
            //如果左右存在连续元素，将他们的键值加长
            if (map.find(nums[i] - 1) != map.end())
            {
                l = std::max(l, mergeCluster(map, nums[i] - 1, nums[i]));
            }
            if (map.find(nums[i] + 1) != map.end())
            {
                l = std::max(l, mergeCluster(map, nums[i], nums[i] + 1));
            }
        }
        return size == 0 ? 0 : l;
    }
  private:
  //聚类同一个连续序列，将当前元素序列两端键值更新为目前为止最长长度，也很巧妙
    int mergeCluster(std::unordered_map<int, int> &map, int left, int right)
    {
        int upper = right + map[right] - 1;
        int lower = left - map[left] + 1;
        int length = upper - lower + 1;
        map[upper] = length;
        map[lower] = length;
        return length;
    }
};

#endif