#include <iostream>
#include <iomanip>

//зло!
using namespace std; //когда ищем в глобальном пространстве имен то еще и там посмотрим

int main()
{
    double z;
    //(cin >> a) >> b;
    while(cin >> z) { // в результате возвращают себя
        cout << "z: " << setprecision(10) << setw(32) << setfill('0') << hex << z << endl;
    }   
}