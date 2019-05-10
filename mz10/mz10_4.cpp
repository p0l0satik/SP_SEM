#include <iostream>
#include <map>
#include <set>
#include <string>
#include <ctype.h>
#include <cstring>
int main(void) {
    std::map<std::string, std::map<char, std::string> > states;
    std::set<std::string> fstates;
    std::string inp, inp_c, inp_n, state, check;
    std::cin >> inp;
    while (std::strcmp(inp.c_str(), "END")) {
        std::cin >> inp_c >> inp_n;
        states[inp][inp_c[0]] = inp_n;
        std::cin >> inp;
    }
    std::cin >> inp;
    while (std::strcmp(inp.c_str(), "END")) {
        fstates.insert(inp);
        std::cin >> inp;
    }
    std::cin >> state;
    std::cin >> check;
    size_t p = 0;
    bool res = true;
    while (res && p < check.size()) {
        auto now = states.find(state);
        if (now == states.end()) {
            res = false;
        } else {
            auto next = (now->second).find(check[p]);
            if (next == (now->second).end()){
                res = false;
            } else {
                p++;
                state = next->second;
            }
        }
    }
    if (res && fstates.find(state) != fstates.end()) {
        std::cout << 1 << std::endl << p << std::endl << state << std::endl;
    } else {
        std::cout << 0 << std::endl << p << std::endl << state << std::endl;
    }
}