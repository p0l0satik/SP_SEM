#include <stdio.h>
void f()
{
    printf("f()\n");
}

void f(int z)
{
    printf("f(int)\n");
}

void f(double d)
{
    printf("f(double)\n");
}

void f (char c)
{
    printf("f(char)\n");
}

void f (long &l)
{
    printf("f(long)\n");
}

void f (const long &l) // елси просто ссылка - неоднозначность, работает ток с константной и неконстантной ссылкой
{
    printf("f(&long)\n");
}

void f(const char *) {
    printf("char *\n");
}

int main ()
{
    f();
    int z = 0;
    f(z);
    double d = 0;
    f(d);

    //promotion
    char c;
    f(c);

    //нет промоушена, либо инт либо дабл, они равнозначны => неоднозначность
    // long l;
    // f(l);

    unsigned long ul;
    f(long(ul));
    // нет функции от чаров, переменная от лонга приведенная к чару, вызываем инт ХАХАХАХАХАХАХХАХАХАХА

    /*
    1. Identity,  const T & T
    2. add const, 
    3. promotion
    4. conversion
    5. user
    6. ... - ellipsis
    */
    // если есть вложенные области видимости ищем в первой встречающейся области все перегрузки, ДАЛЬШЕ НЕ ИДЕМ
    










}