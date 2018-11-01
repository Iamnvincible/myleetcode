#include <iostream>
#include <vector>
#include "Solution_134.hpp"
using namespace std;
int main(int argc, char const *argv[]) {
  vector<int> gas = {1,2,3,4,5,5,70};
  vector<int> cost = {2,3,4,3,9,6,2};
  Solution_134 s;
  int res = s.canCompleteCircuit(gas, cost);
  cout << res << endl;
  return 0;
}