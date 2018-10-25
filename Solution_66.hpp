#ifndef SOLUTION_66
#define SOLUTION_66
#include <vector>
class Solution_66 {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    std::vector<int> res(digits.size() + 1, 0);
    int add = 0;
    res[digits.size()] = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      auto num = digits[i];
      auto temp = res[i + 1] + num + add;
      add = temp / 10;
      res[i + 1] = temp % 10;
    }
    if (add == 1) {
      res[0] = 1;
    } else {
      res.erase(res.begin(), res.begin() + 1);
    }
    return res;
  }
};
class Solution_66 {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    int add = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      auto num = digits[i];
      auto temp = num + add;
      add = temp / 10;
      digits[i] = temp % 10;
    }
    if (add == 1) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};
#endif