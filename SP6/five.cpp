#include <iostream>

// [[nodiscard]]  - запрещаем дискардить возвращаемое значение
int func(int z) {
    return -1;
}

//[[nodiscard]]
bool func(int z, int &res) {
    return -1;
}

//[nodiscard]
std::pair<bool, int> func3(int z){

}

int main(void) {
    func(10);
    if (auto[res, val] = func3(10); res) { //python люблю ******

    }
}