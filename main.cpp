#include <iostream>
#include <string>
#include <vector>
#include "Tree/Solution_95.hpp"
#include "Tree/TreeTestUtil.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Solution_95 s;
  auto root = s.generateTrees(3);
  for (size_t i = 0; i < root.size(); i++) {
    string out = treeNodeToString(root[i]);
  }

  return 0;
}