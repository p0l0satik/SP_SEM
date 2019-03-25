class A
{
    char *a{};
    char *b{};
    size_t az{}, bz{};
    public:
    A(char *a, size_t az, char *b, 
    size_t bz) : a(new char[az]), b(new char[bz]), bz(bz){} //утечка памяти если new у б не сработает    
};

A &operator = (const A &a) {
    if (&a != this) return *this;
    delete[] a;
    delete[] b;
    a = new char[];//..
    b = new char[];//..
    //если будет эксепт то разрушим объект - пиши свап
}
