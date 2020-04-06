#include <iostream>
#include <string>

using namespace std;

#include "edx-io.hpp"
#define io io
#define cout io

int binSearch(const int *arr, int n, int digit){
    int l = -1;
    int r = n;
    while (r > l + 1){
        int m = (l + r) / 2;
        if (arr[m] < digit) {
            l = m;
        } else {
            r = m;
        }
    }
    if (r < n && arr[r] == digit){
        return r;
    } else {
        return -1;
    }
}


int searchMax(int *arr, int n, int digit, int indexMin){
    int l = indexMin;
    int r = n;
    while ( r > l + 1){
        int m = (l + r) / 2;
        if (arr[m] == digit){
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    int n;
    io >> n;
    int* arr = new int[n+1];
    for (int i = 0; i < n; ++i) {
        io >> arr[i];
    }

    int requestCount;
    io >> requestCount;
    for (int i = 0; i < requestCount; ++i) {
        int digit;
        io >> digit;
        int indexMin = binSearch(arr, n, digit);
        if (indexMin == -1){
            io << indexMin << ' ' << indexMin << '\n';
        } else {
            int indexMax = searchMax(arr, n, digit, indexMin);
            cout << indexMin + 1 << ' ' << indexMax + 1 << '\n';
        }
    }
    return 0;
}