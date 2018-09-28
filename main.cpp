#include "Fibonacci.h"
int main(int argc, char const *argv[])
{
    Fibonacci s;
    if (argc > 1)
    {
        int num = atoi(argv[1]);
        s.test(num);
        //s.test2(num);
    }
    return 0;
}
