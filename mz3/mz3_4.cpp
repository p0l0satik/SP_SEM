#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>


class F {
    size_t n;
    double sum;
public:
    F() : n(0), sum(0){}
    void operator ()(double a){
        sum += a;
        ++n;
    }
    double get_mid() const{
        return sum / n;
    }
};
enum
{
    PRESIC = 10,
    APR = 10
};
int main(void) {
    std::vector <double> row;
    double inp;
    while(std::cin >> inp){
        row.push_back(inp);
    }
    size_t fr_aprx = row.size() / PRESIC;
    std::sort(row.begin() + fr_aprx, row.end() - fr_aprx);
    size_t sc_aprx = (row.size() - 2 * fr_aprx) / PRESIC;
    size_t aprx = sc_aprx + fr_aprx;
    std::cout << std::fixed << std::setprecision(PRESIC) << 
    (std::for_each(row.begin() + aprx, row.end() - aprx, F())).get_mid() << std::endl;
}