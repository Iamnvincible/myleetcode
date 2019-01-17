#ifndef SOLUTION_13
#define SOLUTION_13
/* Roman numerals are represented by seven different symbols: 
I, V, X, L, C, D and M. 
把罗马数字转换成普通数字
注意罗马数字的表示方式，右边比左边大是右-左
从右向左遍历
如果遍历到的符号比已有的值大或比右边的符号大，将符号代表的值加入，
否则减去
*/
#include <string>
#include <unordered_map>
class Solution_13 {
 public:
  int romanToInt(std::string s) {
    std::unordered_map<int, int> m;
    char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int values[7] = {1, 5, 10, 50, 100, 500, 1000};
    for (int i = 0; i < 7; i++) {
      m[symbol[i]] = values[i];
    }
    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (m[s[i]] >= res || m[s[i]] >= m[s[i + 1]]) {
        res += m[s[i]];
      } else {
        res -= m[s[i]];
      }
    }
    return res;
  }
};
#endif