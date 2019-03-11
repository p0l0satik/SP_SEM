/* template<prarams>
params:
type
 целые параметры
 ... - переменное число аргументов

 //ordinary func has priority under template ones
*/
#include <iostream>
using namespace std;

template <typename C>
//template func
void myswap(C &a, C &b)
{
    // move is a magic;
    cout <<"c&" << endl;
    auto tmp{move(a)};
    a = move(b);
    b = move(tmp);

}

//специализация шаблона
//шаблонная функция с фикс аргументами
template <> 
void myswap(int &a, int &b)
{
    cout <<"spec int" << endl;
}

template<class C> //class = template
void myswap(C *a, C *b)
{
    auto tmp{*a};
    *a = *b;
    *b = tmp;
}



int main()
{
    int a = 10, b = 20;
    // когда в первый раз используем функцию шаблон инстанциируется шаблонами
    myswap<int>(a, b);
    cout << a << ' ' << b << endl;
    myswap<int>(a, b);
    cout << a << ' ' << b << endl;
    double c = 1.1, d = 2.2;
    myswap(c, d);
    cout << c << ' ' << d << endl;
    double *pc = &c, *pd = &d;
    cout << (void *) pc << ' ' << (void *) pd << endl;
    myswap <double *> (pc, pd); //явно указали что хотим ту что со ссылками, иначе будет указатели
    cout << (void *) pc << ' ' << (void *) pd << endl;

    return 0;
}