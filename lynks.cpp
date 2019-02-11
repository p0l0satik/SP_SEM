#include <stdio.h>
void func(const int &z){
    printf("%d\n", z);
}

void swap(int &a, int &b)
{
    int x = a;
    a = b;
    b = x;
    
}

int main(){
    int a = 10;
    int &b = a;
    b = 11;
    ++b;
    //ссылка не может быть нулевой

    int &c{b}; // тоже указывает на a

    swap(c, y);
    char z = 120;
    // swap (c, (int) z); // нельзя так
    func(a);
    func((int) z); //если константная то можно, с числом попробукй
    
}