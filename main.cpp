#include <iostream>
#include <vector>
#include "Solution_137.hpp"
using namespace std;
int main(int argc, char const *argv[]) {
  vector<int> ratings = {2,2,3,2};
  Solution_137 s;
  int res = s.singleNumber(ratings);
  cout << res << endl;
  return 0;
}