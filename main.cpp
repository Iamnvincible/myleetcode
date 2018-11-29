#include <iostream>
#include <string>
#include "String\Solution_8.hpp"
using namespace std;
int main(int argc, char const* argv[]) {
  Solution_8 s;
  auto k = s.myAtoi("-2147483648");
  cout << k << endl;
  string str = "1234567890";
  auto x = str.substr(3, 2);
  cout << x << endl;
  // s.test();
  return 0;
}