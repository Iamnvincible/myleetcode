#include <iostream>
#include "Fibonacci.h"
#include "Solution_70.hpp"
int main(int argc, char const *argv[]) {
  Solution_70_bak2 s;
  Solution_70_bak1 s1;
  Solution_70_bak3 s0;
  Fibonacci f;
  int c = 40;
  s1.test(c);
  s.test(c);
  f.test(c+1);
  s0.test(c);

  return 0;
}