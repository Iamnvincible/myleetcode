#ifndef FIBONACCI
#define FIBONACCI
#include <iostream>
class Fibonacci
{
  public:
    unsigned long long *Fibo(unsigned long long n)
    {
        if (n == 0)
        {
            unsigned long long *a = (unsigned long long *)malloc(sizeof(unsigned long long) * 2);
            a[0] = 1;
            a[1] = 0;
            return a;
        }
        else
        {
            if (n % 2 == 0)
            {
                unsigned long long *m = Fibo(n / 2);
                unsigned long long fn = (2 * m[0] - m[1]) * m[1];
                unsigned long long fn1 = m[1] * m[1] + m[0] * m[0];
                unsigned long long *a = (unsigned long long *)malloc(sizeof(unsigned long long) * 2);
                a[0] = fn1;
                a[1] = fn;
                return a;
            }
            else
            {
                unsigned long long *m = Fibo(n / 2);
                unsigned long long fn = m[1] * m[1] + m[0] * m[0];
                unsigned long long fn1 = (2 * m[1] + m[0]) * m[0];
                unsigned long long *a = (unsigned long long *)malloc(sizeof(unsigned long long) * 2);
                a[0] = fn1;
                a[1] = fn;
                return a;
            }
        }
    }
    int Fibo2(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        else
        {
            return Fibo2(n - 2) + Fibo2(n - 1);
        }
    }
    void test()
    {
        auto x = Fibo(20);
        std::cout << x[1] << std::endl;
    }
    void test(int n)
    {
        auto x = Fibo(n);
        std::cout << x[1] << std::endl;
    }
    void test2(int n)
    {
        auto x = Fibo2(n);
        std::cout << x << std::endl;
    }
};
#endif