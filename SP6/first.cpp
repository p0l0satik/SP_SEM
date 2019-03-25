struct A{
    void f(int);
};

struct B : A
{
    void f(double);  
};

int main(int argc, char const *argv[])
{
    A a;
    B b;
    
    a.f(1.5); //f conversion double to int
    b.f(1); //f conversion int to double
    return 0;
}