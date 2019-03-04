#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::string s, s_r;
    while (std::cin >> s) 
    {
        long long int t = 0;
        s_r = s;
        reverse(s_r.begin(), s_r.end());
        while(!equal(s_r.begin(), s_r.end() - t, s.begin() + t)) {
            t++;
        }
        std::cout << s.substr(t) << std::endl;
    }
    return 0;
}
