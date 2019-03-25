#include <cstdint>
#include <iostream>

struct Except
{
    int64_t ret;
    Except(int64_t r): ret(r) {};
};


void f(int64_t a, int64_t b, int32_t k) {
    if(k == 0) {
        throw Except(a + b);
    } else if (b == 1) {
        throw Except(a);
    } 
    int64_t tp = 0;
    try {
        f(a, b - 1, k);
    } catch (const Except &z) {
        tp = z.ret;
    }

    try {
        f(a, tp, k - 1);
    }catch (const Except &z) {
        throw Except(z.ret);
    }
}

int main() {
    int64_t a, b;
    int32_t k;
    while(std::cin >> a >> b >> k) {
        try{
            f(a, b, k);
        } catch (const Except &z) {
            std::cout << z.ret << std::endl;
        }
        
    }
}