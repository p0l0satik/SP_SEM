#include <iostream>
#include <map>
#include <set>
#include <string>
#include <ctype.h>

int main(void) {
    std::multimap<char, std::string> rules;
    std::set<char> V;
    std::string inright, inleft;
    while (std::cin >> inleft >> inright) {
        rules.insert(std::make_pair(inleft[0], inright));
    }
    bool change = true;
    V.insert('S');
    while(change) {
        change = false;
        for (auto it = rules.begin(); it != rules.end(); ++it) {
            if (V.find(it->first) != V.end()) {
                for (size_t t = 0 ; t != (it->second).size(); ++t){
                    if (isupper((it->second)[t]) && V.find((it->second)[t]) == V.end()){
                        V.insert((it->second)[t]);
                        change = true;
                    }
                }
            }
        }
    }
    for (auto it = rules.begin(); it != rules.end(); ++it) {
        if (V.find(it->first) != V.end()) {
            std::cout << it->first << " " << it->second << std::endl;
        }
    }
}