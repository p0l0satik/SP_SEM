#include <iostream>
#include <vector>
template <typename T>
typename T::value_type process(const T &v, const int last = 5)
{
    typename T::value_type s{};
    int t = 0;
    for (auto it = v.rbegin(); (it != v.rend() && t < last); ++t, ++it){
        if (t % 2 == 0){
            s += *it;
        }
        
    }
    return s;
}

int main(){
    std::vector <int> v = {1, 2, 3, 4, 5};
    std::cout << process(v);
}