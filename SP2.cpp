/*
нельзя перегрузить
::
.
? :
sizeof

совсем простые + - ~ !

бинарные + - * / & | ^ == >= <= 
*/
#include <iostream>

using namespace std;

struct B
{
    int b;
    B(int b) : b(b) {};

};

struct A
{
private:
    int a;
public:
    A(int a) : a(a) {}
    A(const B &b) : a(10)
    {
        cout << "A::const B" << endl;
    }

    int operator + () const
    {
        cout << "A::operator +()" << endl;

    }
    int operator -()const;
    // int operator -(const A &a, const A &b)const
    // {
    //     cout << "A - B" << endl;   
    // }
    int operator + (const A &a) const
    {   
        cout << "A + B" << endl;
    }
};

int A::operator -()const // вынесли из класса
{
    cout << "A::operator -()" << endl;
    return -a;
}
int operator !(const A &a) {
    cout << "operator" << endl;
    return 1;
}
int main()
{
    A a(1), a2(2);
    +a;
    -a;
    B b(2);
    !b;
    a + b;

    int e{};
    


}