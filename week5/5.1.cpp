#include <iostream>
#include <string>

using namespace std;

#include "edx-io.hpp"
#define cin io
#define cout io


int main() {
    int n;
    cin >> n;
    int* heap = new int[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> heap[i];
    }

    bool isHeap = true;
    for (int i = n; isHeap && i > 1; i--) {
        if (heap[i] < heap[i / 2]){
            isHeap = false;
        }
    }
    cout << (isHeap ? "YES" : "NO");
    return 0;
}