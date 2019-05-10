#include <iostream>
#include <vector>
#include <functional>

template <typename T, typename F>
void myapply(T beg, T end, F f) {
    for (; beg != end; ++beg) {
        f(*beg);
    }
}

template <typename T, typename F>
void myapply(T *beg, T *end, F f) {
    for (; beg != end; ++beg) {
        f(*beg);
    }
}


template <typename Y, typename L>
std::vector<std::reference_wrapper <typename Y::value_type> > myfilter2(Y beg, Y end, L f){
    std::vector<std::reference_wrapper<typename Y::value_type> > ret;
    for (; beg != end; ++beg) {
        if (f(*beg)) {
            ret.insert(ret.end(), std::reference_wrapper<typename Y::value_type>(*beg));
        }
    }
    return ret;
}

template <typename Y, typename L>
std::vector<std::reference_wrapper <Y> > myfilter2(Y *beg, Y *end, L f){
    std::vector<std::reference_wrapper<Y> > ret;
    for (; beg != end; ++beg) {
        if (f(*beg)) {
            ret.insert(ret.end(), std::reference_wrapper<Y>(*beg));
        }
    }
    return ret;
}
