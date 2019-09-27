#include <iostream>
#include <string>
#include <vector>
#include "Tree/Solution_105.hpp"
#include "Tree/TreeTestUtil.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Solution_105 s;
  vector<int> pre = {3, 9, 20, 15, 7};
  vector<int> ino = {9, 3, 15, 20, 7};
  auto root = s.buildTree(pre, ino);
  string output = treeNodeToString(root);
  cout << output << endl;
  return 0;
}