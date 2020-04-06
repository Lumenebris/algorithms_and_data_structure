#include <iostream>
#include <string>

using namespace std;

#include "edx-io.hpp"
#define cin io
#define cout io


int main() {
    int n;
    char c;
    int* stack = new int[1000000];
    int ctr = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == '+') {
            cin >> stack[ctr++];
        }
        else {
            cout << stack[--ctr] << '\n';
        }
    }

    return 0;
}