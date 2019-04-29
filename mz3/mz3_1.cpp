#include <iostream>
#include <vector>

void process(const std::vector <int> &from, std::vector <int> &to, int step) {

    auto i = to.begin();
    auto check = from.begin();
    for (auto it = from.begin(); it < from.end();  ++i) {
        if (i == to.end()) {
            break;
        }
        *i = *it;
        it += step;
        if (it < check) {
            break;
        }
        
    }

    for (auto it = to.rbegin(); it < to.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}
