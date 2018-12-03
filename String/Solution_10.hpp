#ifndef SOLUTION_10
#define SOLUTION_10

/* 
Given an input string (s) and a pattern (p),
implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

实现一个包括了.和*的正则表达式
递归法和动态规划法

动态规划画出一个表格
字符串长度为col,匹配串长度为row
表格大小col+1 * row +1
 */
#include <string>
#include <vector>
/*
- 若p为空，若s也为空，返回true，反之返回false

- 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false

-若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配

-若p的第二个字符为*，若s不为空且字符匹配，调用递归函数匹配s和去掉前两个字符的p，若匹配返回true，否则s去掉首字母

- 返回调用递归函数匹配s和去掉前两个字符的p的结果
 */
class Solution_10
{
public:
  bool isMatch(std::string s, std::string p)
  {
    //模式串为空的情况
    if (p.empty())
      return s.empty();
    //第二个模式为*的情况
    if (p.size() > 1 && p[1] == '*')
    {
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
    else
    {
      return !s.empty() && (s[0] == p[0] || p[0] == '.') &&
             isMatch(s.substr(1), p.substr(1));
    }
  }
};

class Solution_10_bak
{
public:
  bool isMatch(std::string s, std::string p)
  {
    int row = p.size();
    int col = s.size();
    std::vector<std::vector<bool>> dp(row + 1, std::vector<bool>(col + 1, false));
    dp[0][0] = true;
    //第一行剩余元素全部变为false，因为pattern如果是空串，那么只要s不是空串，都不能匹配
    for (int i = 1; i <= col; i++)
    {
      dp[0][i] = false;
    }
    //初始化第0列，此时s是空串，所以只能是x*y*这种形式的
    //注意，j-1代表的真实的p的索引
    for (int j = 1; j <= row; j++)
    {
      //1.只有一个字符来匹配空肯定是false
      //2.当前匹配模式为*才有可能是x*y*这种形式
      //3.并且上上一行匹配成功（也是*才能成功吧 =='*'
      dp[j][0] = (j > 1) && p[j - 1] == '*' && dp[j - 2][0];
    }
    //每次pattern字符串往下走一个字符，和所有的目标字符串子串进行匹配。
    for (int i = 1; i <= col; i++)
    {
      //此时子字符串是s的前i个字符
      //判断是否成功匹配
      //1.当前模式为*，
      //情况1：
      //'*'代表空串，即0次复制
      //dp[j-2][i] = 1

      //情况2：
      //'*'表示对前一个字符的若干次复制。
      //dp[j][i-1] = 1 表示前一列的j行为true，即*匹配次数少一次时成功匹配
      //且 pattern字符串j-2位置的字符和目标字符串i-1位置的字符相同
      //(因为0位置表示了空串，所以数组中i位置代表的是字符串中的i-1位置)
      //或者pattern字符串j-2位置的字符为'.',

      //2.当前模式不为*，只需要判断是否是'.'或相同字符 且前面匹配成功即dp[j-1][i-1]为true
      for (int j = 1; j <= row; j++)
      {
        if (p[j - 1] == '*')
        {
          dp[j][i] = (dp[j - 2][i]) || (dp[j][i - 1] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
        }
        else
        {
          dp[j][i] = (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && dp[j - 1][i - 1];
        }
      }
    }
    return dp[row][col];
  }
};
#endif