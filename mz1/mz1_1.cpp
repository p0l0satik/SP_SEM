#include <iostream>

struct Sum
{
    int sum;
    Sum() = default;
    Sum(int a, int b) 
    {
        sum = a + b;
    }
    operator const int() const
    {
        return sum;
    }

    int get() const 
    {
        return sum;
    }
};
