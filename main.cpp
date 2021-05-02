#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
// #include "Tree/Solution_95.hpp"
// #include "Tree/TreeTestUtil.hpp"
#include "DP/Solution_53.hpp"
using namespace std;
using namespace chrono;

int main(int argc, char const *argv[]) {
  auto _start_clock = system_clock::now();
  // start
  // code below>3
  //-------------
  Solution_53 s;
  vector<int> array = {1, 3, 4, -5, 6, -6, 5, 4, 3, -1, 6, -3, 2, 5, -2};
  int res = s.maxSubArray(array);
  cout << res << endl;
  //-------------
  // stop
  // DONT code below
  auto _stop_clock = system_clock::now();
  auto _duration_time = duration_cast<microseconds>(_stop_clock - _start_clock);
  cout << "costs "
       << double(_duration_time.count()) * microseconds::period::num /
              microseconds::period::den
       << " second(s)" << endl;
  return 0;
}