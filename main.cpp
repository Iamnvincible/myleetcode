#include <iostream>
#include <string>
#include <vector>
#include "Tree/Solution_114.hpp"
#include "Tree/TreeTestUtil.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  string lines[] = {
      "[3,1,4,null,2,null,6,null,null,5]",
      "[5,1,null,null,3,2,4]",
      "[1,null,2,3]",
  };
  for (auto line : lines) {
    auto root = generate_tree(line);
    Solution_114_back b;
    b.flatten(root);
    print_tree(root);
  }
  return 0;
}