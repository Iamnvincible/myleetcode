#ifndef SOLUTION_125
#define SOLUTION_125
/* Given a string,
determine if it is a palindrome,
considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem,
we define empty string as valid palindrome.
判断回文序列
给出一个字符串，只考虑字母数字，不考虑字母的大小写，判断这个字符串是否回文

相向双指针做法
从两个指针从两边靠拢，跳过非字母数字 isalnum，两边指针自增或自减
转换小写后判断 tolower，不相等立即返回 false。能成功遍历完成即为回文。
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