#include <stdexcept>
#include <iostream>
struct Except
{
    
};

// noexcept - елси не пользуем исключениями

int foo(int z) {
    std::cout << z << std::endl;
    if (z > 0) 
            return foo(z - 1);
    throw Except();
}

int main(){
    try{
        foo(10);
    } catch (const Except &z) {
        throw; //перевыбрасывает исключение; если убрать конст можно химичить исключение

    }
}