#ifndef SOLUTION_7
#define SOLUTION_7
#include <iostream>
class Solution_7
{
  public:
    int reverse(int x)
    {
        int res = 0, res0 = 0, temp = 0;
        while (x != 0)
        {
            temp = (x - (x / 10) * 10);
            res0 = res * 10 + temp;
            if ((res0 - temp) / 10 != res)
            {
                return 0;
            }
            res = res0;
            x /= 10;
        }
        return res;
    }
    void test()
    {
        auto res = reverse(123);
        std::cout << res << std::endl;
    }
};
#endif