#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
// include solution file
// #include "String/Solution_2730.hpp"
using namespace std;
using namespace chrono;

int main(int argc, char const *argv[]) {
  auto _start_clock = system_clock::now();
  // define solution class and give test case
  // and run the function of the class and get the result
  // ---example begin--
  // Solution_2730 s;
  // string str = "5494";
  // int res = s.longestSemiRepetitiveSubstring(str);
  // cout << res << endl;
  // ---example end---
  // code below>3
  //-------------

  //-------------
  // code above
  //  DONT code below
  auto _stop_clock = system_clock::now();
  auto _duration_time = duration_cast<microseconds>(_stop_clock - _start_clock);
  cout << "costs "
       << double(_duration_time.count()) * microseconds::period::num /
              microseconds::period::den
       << " second(s)" << endl;
  return 0;
}