#include <iostream>

struct A
{
private:
    int num;
    bool flag;
public:
    A(): flag(false)
    {
        std::cin >> num;
    }

    A(const A &b) : flag(true)
    {   
        std::cin >> num;
        num += b.num;
    }

    ~A()
    {
        if (flag) {
            std::cout << num << std::endl;
        }
        
    }

};

