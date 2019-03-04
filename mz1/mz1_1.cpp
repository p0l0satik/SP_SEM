#include <iostream>

struct Sum
{
private:
    int sum;
public:
    Sum() = default;
    Sum(int a, int b): sum (a + b)
    {
    }

    Sum(const Sum &a, int c): sum (a.sum + c) 
    {
    }

    int get() const 
    {
        return sum;
    }
};
