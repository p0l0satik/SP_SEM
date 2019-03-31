#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <vector>

void process(const std::vector <int> &v1, std::vector <int> &v2) {
    if(v1.size() == 0){
        return;
    }
    std::vector <int> v_copy = v1;
    
    std::sort(v_copy.begin(), v_copy.end());
    v_copy.erase(std::unique(v_copy.begin(), v_copy.end()), v_copy.end());
    int size = v2.size();
    int good_ptr = 0, bad_ptr = 0;
    auto t = v_copy.begin();
    while(*t < 0){
        t++;
    }
    if(t >= v_copy.end()){
        return;
    }
    while(bad_ptr != *t && bad_ptr < size){
        bad_ptr ++;
    }
    while(good_ptr <= *t && good_ptr < size){
        good_ptr++;
    }
    t++;
    while (good_ptr == *t && good_ptr < size){
        t++;
        good_ptr++;
    }

    while(good_ptr < size){       
        std::swap(*(v2.begin() + good_ptr), *(v2.begin() + bad_ptr));
        good_ptr++;
        bad_ptr++;
        while (good_ptr == *t && good_ptr < size){
            t++;
            good_ptr++;
        }
        
    }
    v2.erase(v2.begin() + bad_ptr, v2.end());
    
}


