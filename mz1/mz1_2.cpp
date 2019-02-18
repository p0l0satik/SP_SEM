#include <iostream>

struct A
{
    int num;
    int flag;
    A()
    {
        flag = 0;
        std::cin >> num;
    }

    A(const A &b)
    {   
        std::cin >> num;
        num += b.num;
        flag = 1;
    }

    ~A()
    {
        if (flag) {
            std::cout << num << std::endl;
        }
        
    }

};
