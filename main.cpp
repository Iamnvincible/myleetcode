#include <iostream>
#include <vector>
#include "Solution_135.hpp"
using namespace std;
int main(int argc, char const *argv[]) {
  vector<int> ratings = {1, 2, 3, 2, 3};
  Solution_135 s;
  int res = s.candy(ratings);
  cout << res << endl;
  return 0;
}