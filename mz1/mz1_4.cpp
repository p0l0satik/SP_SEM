#include <iostream>
#include <iomanip>
#include <math.h>

int main() {
    int n = 0;
    double sum = 0, sum_sqr = 0, a = 0;
    while (std::cin >> a) {
        n++;
        sum += a;
        sum_sqr += a * a;
    }
    std::cout << std::setprecision(10) << sum / n << std::endl;
    std::cout << std::setprecision(10) << sqrt(sum_sqr / n - (sum / n)*(sum / n)) << std::endl;
}