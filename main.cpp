#include <chrono>
#include <iostream>
#include <string>
#include <vector>

// #include "Tree/Solution_95.hpp"
// #include "Tree/TreeTestUtil.hpp"
#include "Enum/Solution_77.hpp"
using namespace std;
using namespace chrono;

int main(int argc, char const *argv[]) {
  auto start = system_clock::now();
  // start
  // code below>3
  Solution_77 s;
  auto res = s.combine(10, 3);
  for (auto &&i : res) {
    for (auto &&j : i) {
      cout << j << " ";
    }
    cout << endl;
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