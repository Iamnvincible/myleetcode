#include <iostream>
#include <vector>
#include "Sort/Solution_147.hpp"
using namespace std;
void print(vector<int> v) {
  for (auto i : v) {
    cout << i << ",";
  }
  cout << endl;
}
int main(int argc, char const *argv[]) {
  Solution_147 b;
  b.test();
  return 0;
}