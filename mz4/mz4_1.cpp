#include <iostream>
#include <vector>
template <typename T>
typename T::value_type process(const T &v)
{
    typename T::value_type s{};
    int t = 0;
    for (auto it = v.rbegin(); (it != v.rend() && t < 5); ++t, ++it)
    {
        if (t % 2 == 0)
        {
            s += *it;
        }
        
    }
    return s;
}
