//traits -чЁрты 
#include <iostream>
using namespace std;

template<typename T>

struct is_int
{
    static constexpr auto value = false;

};

template<>
struct is_int<int>
{
    static constexpr auto value = true;
};


int main()
{
    cout << is_int<double>::value << endl;
    cout << is_int<int>::value << endl;
    int x;
    static_assert(is_int<decltype(x)>::value);//не скомпилится если не инт
    if constexpr(constexpr is_int<decltype(x)>::value){
        cout<< x << endl;
    }
}