#include <iostream>
#include <vector>
#include "Solution_73.hpp"
int main(int argc, char const *argv[]) {
  Solution_73_bak s;
  std::vector<std::vector<int>> v = {
      {1, 2, 3, 4}, {5, 0, 5, 2}, {8, 9, 2, 0}, {5, 7, 2, 1}};
  s.setZeroes(v);

  return 0;
}