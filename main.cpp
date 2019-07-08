#include <time.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  time_t t = time(NULL);
  cout << t << endl;
  cout << "hello world" << endl;
  return 0;
}