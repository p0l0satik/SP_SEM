#include <iostream>
#include <vector>
#include <functional>
using namespace std;


template <typename T>
auto sum(T beg, T end, typename T::value_type s = {})
{
      //лезем в контейнер получаем тип элемента
    // typename T::value_type s{};

    for (; beg != end; ++beg)
    {
        s += *beg;
    }
    return s;
}

template <typename T>
auto sum(T *beg, T *end,  T s = {})
{
      //лезем в контейнер получаем тип элемента
    // typename T::value_type s{};

    for (; beg != end; ++beg)
    {
        s += *beg;
    }
    return s;
}
int main()
{
    vector v1{1, 2, 3, 4, 5};
    cout << sum(v1.begin(), v1.end(), 0) << ' ' << endl; 
    cout << sum(v1.begin() + 1, v1.end() - 1, 0) << ' ' << endl;
    double v4[]{1, 2, 3, 4, 5, 6};
    cout << sum(v4, v4 + 5, 0.5) << endl; 
    return 0;
}