#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "Tree/Solution_95.hpp"
#include "Tree/TreeTestUtil.hpp"
using namespace std;
using namespace chrono;

int main(int argc, char const *argv[]) {
  auto start = system_clock::now();
  // start
  // code below>3

  Solution_95 s;
  auto root = s.generateTrees(3);
  for (size_t i = 0; i < root.size(); i++) {
    string out = treeNodeToString(root[i]);
    cout << out << endl;
  }

  // stop
  auto end = system_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
  cout << "costs "
       << double(duration.count()) * microseconds::period::num /
              microseconds::period::den
       << " second(s)" << endl;
  return 0;
}