#include <iostream>
#include <string>
#include "Stack_Queue/Solution_150.hpp"
using namespace std;
int main(int argc, char const *argv[]) {
  printf("hello world\n");
  size_t m = 866278171;
  size_t r = 0;
  for (size_t i = 1; i <= m; i++) {
    if ((i & 1) == 1) {
      size_t j = i;
      while (j != 0) {
        if (j % 10 == 3) {
          r++;
        }
        j /= 10;
      }
    }
  }
  cout << r << endl;

  return 0;
}
