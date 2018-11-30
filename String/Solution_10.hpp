#ifndef SOLUTION_10
#define SOLUTION_10
#include <string>
#include <vector>
/*
- 若p为空，若s也为空，返回true，反之返回false

- 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false

-若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配

-若p的第二个字符为*，若s不为空且字符匹配，调用递归函数匹配s和去掉前两个字符的p，若匹配返回true，否则s去掉首字母

- 返回调用递归函数匹配s和去掉前两个字符的p的结果
 */
class Solution_10 {
 public:
  bool isMatch(std::string s, std::string p) {
    //模式串为空的情况
    if (p.empty()) return s.empty();
    //第二个模式为*的情况
    if (p.size() > 1 && p[1] == '*') {
      //情况1：*匹配0次 能匹配成功
      //情况2：s不为空 且 至少匹配了1次 且
      //去掉一个匹配到的字符后--->依然匹配成功
      //例子 ab*a*c*a 匹配 aaa
      //第一轮匹配掉了a 剩下b*a*c*a 匹配 aa
      //第二轮进入isMatch(s, p.substr(2))，匹配串变成a*c*a aa,后面那个或显然为false
      //第三轮进入后面的或，isMatch(s.substr(1), p))，a*c*a a
      //第四轮，进入前面的或，c*a a
      //第五轮，计入前面的或 a a--成功
      //太巧妙了

      return isMatch(s, p.substr(2)) ||
             (!s.empty() && (s[0] == p[0] || p[0] == '.') &&
              isMatch(s.substr(1), p));
    }
    //  (p[1] != '*')第二个模式不是*的情况
    //在s不为空且
    //第一个字符匹配成功且
    //去掉一个字符和模式后依然匹配成功
    //条件下匹配成功
    else {
      return !s.empty() && (s[0] == p[0] || p[0] == '.') &&
             isMatch(s.substr(1), p.substr(1));
    }
  }
};
class Solution_10_bak {
 public:
  bool isMatch(std::string s, std::string p) {
    int m = s.length(), n = p.length();
    std::vector<std::vector<bool> > dp(m + 1, std::vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (p[j - 1] == '*')
          dp[i][j] = dp[i][j - 2] ||
                     (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') &&
                      dp[i - 1][j]);
        else
          dp[i][j] = i > 0 && dp[i - 1][j - 1] &&
                     (s[i - 1] == p[j - 1] || p[j - 1] == '.');
    return dp[m][n];
  }
};
#endif