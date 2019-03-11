
//auto
#include <iostream>
using namespace std;

// функция с автотипом: по ретурн, сама опредеяет что возвращать, не должно быть противоречий в типе
auto f(int s)
{
    cout << s << endl;
    return double(s);

}
//что и зачем неясно
auto g(int s) -> double
{
    cout << s << endl;
    return s;
}


auto h(auto a, auto b)
{
    return a + b;
}

int main()
{
    auto x = 10;
    f(x);
    cout << g(20) << endl;
    cout << h(100, 200) << endl;
}