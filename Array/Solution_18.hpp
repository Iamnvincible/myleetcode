#ifndef SOLUTION_18
#define SOLUTION_18
/*
 *Given an array nums of n integers and an integer target,
 *are there elements a, b, c, and d in nums such that a + b + c + d = target?
 *Find all unique quadruplets in the array which gives the sum of target.
 *Note:
 *The solution set must not contain duplicate quadruplets.
 *用一个哈希表记录任意两个元素的和，变成 two
 *sum，但是哈希表中的值是若干个原始元素下标对pair
 *因为元素可能会重复，筛选掉重复的元素
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
class Solution_18 {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    std::vector<std::vector<int>> result;
    if (nums.size() < 4) {
      return result;
    }
    std::sort(nums.begin(), nums.end());
    std::unordered_map<int, std::vector<std::pair<int, int>>> twosum;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        twosum[nums[i] + nums[j]].push_back(std::pair<int, int>(i, j));
      }
    }
    std::unordered_map<int, bool> record;
    // 没有保证两个数相加=target时，同一个加数作为两个数的加数
    // 可以先内部排序，再整体排序，用unique筛选掉相邻重复元素
    // 但是每个数字出现的次数不能超过实际次数！
    // 如何辨别一个数字的唯一性,下标
    // 下面的循环是没有下标顺序的，所以要在添加结果前看看下标是否是一样的以防同一个元素用了两次
    // 最好还是用下面类的方法,因为依次添加时保证了下标的顺序，所以也不需要内部的排序
    // 如果允许数字相同但是数字的原下标不同的相同结果出现，这种方法就不对了，重复的结果太多了
    for (auto i = twosum.begin(); i != twosum.end(); i++) {
      int a = i->first;      // 键
      int diff = target - a; // 键
      if (twosum.find(diff) != twosum.end()) {
        // 找过了
        if (record.find(diff) != record.end()) {
          continue;
        }
        // 没找过,找到了
        record[diff] = true;
        record[a] = true;
        auto found = twosum[diff];      // vector
        int asize = (i->second).size(); // 值
        int bsize = found.size();
        for (int j = 0; j < asize; j++) {
          for (int k = 0; k < bsize; k++) {
            int x = (i->second)[j].first;
            int y = (i->second)[j].second;
            int p = found[k].first;
            int q = found[k].second;
            if (x != p && y != q && x != q && y != p)
              result.push_back({nums[x], nums[y], nums[p], nums[q]});
          }
        }
      }
    }
    for (int i = 0; i < result.size(); i++) {
      std::sort(result[i].begin(), result[i].end());
    }
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
  }
  void test() {
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    auto v = fourSum(nums, target);
    for (auto i : v) {
      for (auto j : i) {
        std::cout << j << " ";
      }
      std::cout << std::endl;
    }
  }
};
class Solution_18_bak {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    std::vector<std::vector<int>> result;
    if (nums.size() < 4)
      return result;
    sort(nums.begin(), nums.end());
    std::unordered_map<int, std::vector<std::pair<int, int>>> cache;
    for (size_t a = 0; a < nums.size(); ++a) {
      for (size_t b = a + 1; b < nums.size(); ++b) {
        cache[nums[a] + nums[b]].push_back(std::pair<int, int>(a, b));
      }
    }

    for (int c = 0; c < nums.size(); ++c) {
      for (size_t d = c + 1; d < nums.size(); ++d) {
        const int key = target - nums[c] - nums[d];
        if (cache.find(key) == cache.end())
          continue;
        const auto &vec = cache[key];
        for (size_t k = 0; k < vec.size(); ++k) {
          // c之前的元素以及操作过了，跳过以避免重复
          if (c <= vec[k].second)
            continue;
          result.push_back(
              {nums[vec[k].first], nums[vec[k].second], nums[c], nums[d]});
        }
      }
    }
    // 对向量的向量排序，仅仅是从第0位到最后一位依次排
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
  }
  void test() {
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    auto v = fourSum(nums, target);
    for (auto i : v) {
      for (auto j : i) {
        std::cout << j << " ";
      }
      std::cout << std::endl;
    }
  }
};
class Solution_18_2 {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    //refer to Solution 15, three sum, but be more careful.
    std::vector<std::vector<int>> result;
    int size = nums.size();
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 3; i++) {
      long first = nums[i];
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      if (first + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
        break;
      if (first + nums[size - 1] + nums[size - 2] + nums[size - 3] < target)
        continue;
      for (int j = i + 1; j < size - 2; j++) {
        int second = nums[j];
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        int m = j + 1;
        int n = size - 1;
        if (first + second + nums[m] + nums[m + 1] > target)
          break;
        if (first + second + nums[n] + nums[n - 1] < target)
          continue;
        while (m < n) {
          long sum = first + second + nums[m] + nums[n];
          if (sum > target) {
            n--;
          } else if (sum < target) {
            m++;
          } else {
            result.push_back({nums[i], nums[j], nums[m], nums[n]});
            n--;
            while (m < n && nums[n] == nums[n + 1]) {
              n--;
            }
            m++;
            while (m < n && nums[m] == nums[m - 1]) {
              m++;
            }
          }
        }
      }
    }
    return result;
  }
};
#endif