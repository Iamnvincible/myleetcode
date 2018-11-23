#ifndef SOLUTION_125
#define SOLUTION_125
/* Given a string,
determine if it is a palindrome,
considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem,
we define empty string as valid palindrome.
判断回文序列
只考虑字母数字，不考虑字母的大小写
从两边靠拢
判断符合字母数字条件后
统一转为大写或小写判断
 */
#include <string>
class Solution_125 {
 public:
  bool isPalindrome(std::string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
      if (!isalnum(s[i])) {
        i++;
      } else if (!isalnum(s[j])) {
        j--;
      } else {
        if (tolower(s[i]) == tolower(s[j])) {
          i++;
          j--;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
#endif