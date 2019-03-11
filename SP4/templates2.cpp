#include <iostream>
#include <vector>
#include <functional>
using namespace std;


template <typename T>
auto sum(const T &v, typename T::value_type s = {})
{
      //лезем в контейнер получаем тип элемента
    // typename T::value_type s{};

    for (const auto &x : v)
    {
        s += x;
    }
    return s;
}

template <typename T, typename F>
auto accum(const T &v, F f, typename T::value_type s = {})
{
  
    for (const auto &x : v)
    {
        f(s, x);
    }
    return s;
}

// template <typename T>
// typename T::value_type sum2(const T &v)
// {
//     //лезем в контейнер получаем тип элемента
//     typename T::value_type s = typename T::value_type();

//     for (typename T::const_iterator i = v.begin(); i != v.end(); ++i)
//     {
//         s += *i;
//     }
//     return s;
// }

void func(int &s, int x)
{
    s += x;
}

struct z
{
    void operator()(int &s, int &x) const{s += x;}
};

template <typename T>
struct Y
{
    void operator()(T &s, T x) {s +=x;}
};
int main()
{
    vector v1{1, 2, 3, 4, 5};
    cout << sum(v1) << ' ' << endl; //sum2(v1) << endl;
    // cout << sum2(v1) << ' ' << endl; не компилится узнай почему
    cout << accum(v1, func, 0) << ' ' << endl; 
    cout << accum(v1, std::function <void(int&, int)> (func), 44) << endl;
    return 0;
}