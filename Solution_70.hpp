#ifndef SOLUTION_70
#define SOLUTION_70
/* You are climbing a stair case.
It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
爬楼梯，一次只能爬一级或两级
给出n级楼梯，求出有多少种不同的方案
如果我们知道爬n-1级和n-2级有多少种方案，那么两者之和就是总方案数了
那么就是斐波那契数列了
有朴素的递归办法（当然会超时）和高效的办法，还有非常高效的递归办法
甚至还有公式法一步到位
 */
#include <cmath>
#include <iostream>
//复杂度O(2^n)
class Solution_70 {
 public:
  int climbStairs(int n) {
    if (n <= 1) {
      return 1;
    } else {
      return climbStairs(n - 1) + climbStairs(n - 2);
    }
  }
  void test(int n) {
    auto v = climbStairs(n);
    std::cout << v << std::endl;
  }
};
//复杂度O(n),记录前面两个数
class Solution_70_bak1 {
 public:
  int climbStairs(int n) {
    int a = 1, b = 1;
    if (n <= 1) {
      return a;
    } else {
      for (int i = 2; i <= n; i++) {
        int temp = b;
        a = a + b;
        b = a;
        a = temp;
      }
      return b;
    }
  }
  void test(int n) {
    auto v = climbStairs(n);
    std::cout << v << std::endl;
  }
};
//复杂度O(logn)，寻找线性代数规律
class Solution_70_bak2 {
 public:
  struct matrix {
    int a;
    int b;
    int c;
    int d;
  };
  int climbStairs(int n) {
    auto x = Fibonacci(n);
    return x.a;
  }
  struct matrix Fibonacci(int n) {
    if (n <= 1) {
      struct matrix res;
      res.a = 1;
      res.b = 1;
      res.c = 1;
      res.d = 0;
      return res;
    } else if (n % 2 == 0) {
      auto Matrix = Fibonacci(n / 2);
      struct matrix res;
      res.a = Matrix.a * Matrix.a + Matrix.b * Matrix.c;
      res.b = Matrix.b * (Matrix.a + Matrix.d);
      res.c = Matrix.c * (Matrix.a + Matrix.d);
      res.d = Matrix.b * Matrix.c + Matrix.d * Matrix.d;
      return res;
    } else {
      auto Matrix = Fibonacci(n / 2);
      struct matrix res;
      res.a = Matrix.a * Matrix.a + Matrix.b * Matrix.c +
              Matrix.c * (Matrix.a + Matrix.d);
      res.b = Matrix.b * (Matrix.a + Matrix.d) + Matrix.b * Matrix.c +
              Matrix.d * Matrix.d;
      res.c = Matrix.a * Matrix.a + Matrix.b * Matrix.c;
      res.d = Matrix.b * (Matrix.a + Matrix.d);
      return res;
    }
  }
  void test(int n) {
    auto v = climbStairs(n);
    std::cout << v << std::endl;
  }
};
//复杂度O(1),通项公式f(n)=1/sqrt(5)*((1+sqrt(5)/2)^n-(1-sqrt(5)/2)^n)
class Solution_70_bak3 {
 public:
  int climbStairs(int n) {
    const double s = sqrt(5);
    return floor((pow((1 + s) / 2, n + 1) + pow((1 - s) / 2, n + 1)) / s + 0.5);
  }
  void test(int n) {
    auto v = climbStairs(n);
    std::cout << v << std::endl;
  }
};
#endif