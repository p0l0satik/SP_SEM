#include <iostream>

void f(int a, int b)
{
    std::cout << "f(int, int)" << std::endl;//endlвызывает flush всегда
}

void f(double a, double b)
{
    std::cout << "f(double, double)" << std::endl;
}

void f(const char *a, double b)
{
    std::cout << "f(const chr *, double)" << std::endl;
}

struct A
{
    A(int z) // пользовательское преобразование типов?
    {
        std::cout << "A::A(int)" << std::endl;
    }
    A(long z) // пользовательское преобразование типов?
    {
        std::cout << "A::A(long)" << std::endl;
    }
    explicit /* запретили преобразование */ A(double z)
    {
        std::cout << "A::A(double)" << std::endl;
    }
    //из класса в ...

    operator const char *() const
    {
        std::cout << "operator const char *" << std::endl;
        return "OK";
    }

    operator const int() const
    {
        std::cout << "operator const int" << std::endl;
        return 1;
    }
}; 

void f(const A &a)
{
    std::cout << "fconst(a&)" << std::endl;
}

int main()
{
    f(1, 2);
    f(1.1, 1.1);
    // f(0, 2.0); //путят для третьей функции
    f(nullptr, 2.0);
    short z = 0;
    f(z, 1);
    f(10);// создали временный объект тут
    f(z); // одно стандратное перед пользовательским
    f(A(1.4)); //явно вызвали конструктор!!

    A a(1.5);
    f(a, 1);
    return 0;
}