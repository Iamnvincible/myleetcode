#ifndef SOLUTION_60
#define SOLUTION_60
/*
 The set [1,2,3,...,n] contains a total of n! unique permutations.
 By listing and labeling all of the permutations in order,
 we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
 Given n and k, return the kth permutation sequence.
Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
获得第k个全排列数列，全排列见Solution31
方法一
31中获得的是下一个全排列，可以使用里面的方法，求k-1次下个全排列数
这种方法求的次数比较多，运行时间较长
方法二
观察全排列数列的规律
同一个数字在最高位出现的次数是后面数字个数的阶乘，(n-1)!
k--,把k作为数组下标形式
k/(n-1)!得到的是有几个数字能够在给定的次位前出现过，
其结果可作为下标获取字符串"1234...n"的数
这样就确定了最高位的数
随后，取k'=k%(n-1)!，这个余数就是后面数字中的第k'个全排列数
这时要从字符串中擦除确定了的最高位数，为下一轮获得数字下标做准备
 */
#include <string>
#include <vector>
#include <sstream>
#include "Solution_31.hpp"
class Solution_60
{
  public:
    std::string getPermutation(int n, int k)
    {
        std::vector<int> s(n);
        for (int i = 0; i < n; i++)
        {
            s[i] = i + 1;
        }
        Solution_31 per;
        for (int j = 0; j < k - 1; j++)
        {
            per.nextPermutation(s);
        }
        std::stringstream ss;
        for (size_t i = 0; i < s.size(); ++i)
        {
            ss << s[i];
        }
        std::string s2; // = ss.str();

        for (size_t i = 0; i < n; i++)
        {
            s2.push_back(s[i] + '0');
        }

        return s2;
    }
};
class Solution_60_bak
{
  public:
    std::string getPermutation(int n, int k)
    {
        std::string s(n, '0');
        std::string res;
        for (int i = 0; i < n; i++)
        {
            s[i] = s[i] + i + 1;
        }
        k--;
        for (int i = 0; i < n; i++)
        {
            int fac = Factorial(n - i - 1);
            auto temp = s[k / fac];
            res.push_back(temp);
            s.erase(k / fac, 1);
            k = k % fac;
        }
        return res;
    }

  private:
    int Factorial(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        return n * Factorial(n - 1);
    }
};
#endif