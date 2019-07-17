#include <iostream>
#include <vector>
#include "Tree/Solution_99.hpp"
using namespace std;
void print(vector<int> v) {
  for (auto i : v) {
    cout << i << ",";
  }
  cout << endl;
}
int main(int argc, char const *argv[]) {
  Solution_99_back b;
  b.test();
  return 0;
}