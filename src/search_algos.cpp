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

int SearchAlgos::ternarySearch (const std::vector<int>& v, int target) {
    int lowEnd = 0;
    int highEnd = v.size() - 1;
    
    while (lowEnd <= highEnd) {
        int mid1 = lowEnd + (highEnd - lowEnd)/3;
        int mid2 = highEnd - (highEnd - lowEnd)/3;

        if (v[mid1] == target) {
            return mid1;
        }
        if (v[mid2] == target) {
            return mid2;
        }

        if (target < v[mid1]) {
            highEnd = mid1 - 1;
        } else if (target > v[mid2]) {
            lowEnd = mid2 + 1;
        } else {
            lowEnd = mid1 + 1;
            highEnd = mid2 - 1;
        }
    }
    return -1;
}