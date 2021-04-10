#ifndef SOLUTION_1
#define SOLUTION_1
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution_1 {
 public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      int find = target - nums[i];
      if (m.find(find) != m.end()) {
        return {i, m[find]};
      } else {
        m.insert({nums[i], i});
      }
    }
    return {};
  }
  void test() {
    Solution_1 s;
    std::vector<int> array = {2, 7, 11, 15};
    int target = 9;
    auto res = s.twoSum(array, target);
    for (auto i = 0; i < res.size(); i++) {
      std::cout << res[i] << std::endl;
    }
  }
};
#endif