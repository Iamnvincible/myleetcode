#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
// #include "Tree/Solution_95.hpp"
// #include "Tree/TreeTestUtil.hpp"
#include "LinkedList/Solution_203.hpp"
// #include "ToBDecided/Solution_7.hpp"
using namespace std;
using namespace chrono;

int main(int argc, char const *argv[]) {
  auto _start_clock = system_clock::now();
  // start
  // code below>3
  //-------------
  Solution_203 s;
  // cout << res << endl;
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