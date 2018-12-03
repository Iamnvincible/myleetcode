#include <iostream>
#include <string>
#include "String\Solution_10.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
  Solution_10_bak s;
  auto x = s.isMatch("aaa", "a*b*a*c*a");
  cout << x << endl;
  return 0;
}