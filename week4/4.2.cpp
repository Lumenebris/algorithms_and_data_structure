#include <iostream>
#include <string>

using namespace std;

#include "edx-io.hpp"
#define cin io
#define cout io

int main() {
    int n;
    char c;
    int* queue = new int[1000000];
    int right = 0;
    int left = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == '+') {
            cin >> queue[right++];
        }
        else {
            cout << queue[left++] << '\n';
        }
    }

    return 0;
}