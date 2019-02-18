#include <iostream>



int main() 
{
    char c;
    char n;
    using std::cin; // на лок уровне
    using std::cout;
    cin >> std::noskipws;
    while (cin >> c){
        cout << c;
        cout << "c" << char(n + '0') << "v" << std::endl; // + приводит чар к инту
        n += (n+1)%10;
    }
}