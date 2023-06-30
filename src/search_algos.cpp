#include "../include/search_algos.h"

int SearchAlgos::binarySearch (const std::vector<int>& v, int target) {
    int lowEnd = 0;
    int highEnd = v.size() - 1;
    int mid = 0;

    while (lowEnd <= highEnd) {
        mid = (lowEnd + highEnd) / 2;
        if (v[mid] == target) {
            return mid;
        } else if (v[mid] < target) {
            lowEnd = mid + 1;
        } else {
            highEnd = mid - 1;
        }
    }
    return -1;
}