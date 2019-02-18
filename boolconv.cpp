#include <iostream>

struct A
{
    // operator bool () const // можно присвоить чему угодно
    // {
    //     std::cout << "op bool" << std::endl;
    // }
    // operator void *() const
    // {
    //     std::cout << "op void*" << std::endl;
    // } 
    explicit operator bool () const // а так можно))))0)
    {
        std::cout << "op bool" << std::endl;
    }
};

int main()
{
    A a;
    // int z = a;

    while(a) {

    }
    return 0;
}