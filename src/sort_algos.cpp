#include "../include/sort_algos.h"

std::vector<int> SortAlgos::bubbleSort (const std::vector<int>& v) {
    std::vector<int> v_tmp = v;
    unsigned int v_tmp_size = v_tmp.size();
    int tmp = 0, adjacement = 0;
    
    for (unsigned int i = 0; i < v_tmp_size - 2; ++i) {
        adjacement = i + 1;
        if (v_tmp[adjacement] < v_tmp[i]) {
            std::swap(v_tmp[adjacement], v_tmp[i]);
        }
    }

    return v_tmp;
}