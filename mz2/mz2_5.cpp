#include<iostream>

class S
{   
    bool prnt;
    bool flag;
    int a;    
public:
    S()
    {
        prnt = false;
        if(std::cin >> a)
        {   
            flag = true;
        } else
        {
            flag = false;
        }
    }
    S(S && v)
    {
        if(std::cin >> a)
        {
            a += v.a;
            prnt = false;
            flag = true;
        } else
        {   
            a = v.a;
            prnt = true;
            flag = false;
        }
    }
    operator bool()
    {
        return flag;
    }
    ~S()
    {
        if(prnt) {
            std::cout << a << std::endl;
        }
        
    }
};

