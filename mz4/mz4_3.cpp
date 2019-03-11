#include <iostream>
#include <vector> 
void f(int a)
{
    std::cout << a + 4 << std::endl;
}

template <typename T, typename F>
void myapply(T beg, T end, F f)
{
    for(; beg != end; ++beg)
    {
        f(*beg);
    }
}

int main()
{
    std::vector<int> v = {1, 2, 3};

    myapply(v.begin(), v.end(), f);
}   