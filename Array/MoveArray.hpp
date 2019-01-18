#ifndef ArrayMove
#define ArrayMove
//把数组元素依次往后移动m位
#include <iostream>
#include <vector>
class AMove {
 public:
  void Move(std::vector<int>& array, int m) {
    int size = array.size();
    if (size <= 0 || m <= 0)
      return;
    else {
      int count = 0;
      int j = 0;
      while (count < size) {
        int temp = array[j];
        bool flag = true;
        for (int i = j; flag || i != j; i = (i + m) % size) {
          int s = array[(i + m) % size];
          array[(i + m) % size] = temp;
          temp = s;
          count++;
          flag = false;
        }
        j++;
      }
    }
  }
  void test() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 2 * v.size(); i++) {
      Move(v, i);
      for (auto& i : v) {
        std::cout << i << " ";
      }
      std::cout << std::endl;
    }
  }
};
#endif