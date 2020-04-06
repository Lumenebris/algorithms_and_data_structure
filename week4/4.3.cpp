#include <iostream>
#include <fstream>
#include <string>

#include "edx-io.hpp"
#define in io
#define out io

using namespace std;

#define LRB '('
#define RRB ')'
#define LSB '['
#define RSB ']'

int main() {
    char* stack = new char[1000000];
    int ctr;
    int n;
    in >> n;

    string sequence;
    for (int i = 0; i < n; i++) {
		ctr = 0;
        in >> sequence;
        bool isWrong = false;
        for (int j = 0; j < sequence.length() && !isWrong; ++j) {
            if (sequence[j] == LSB || sequence[j] == LRB){
                stack[ctr++] = sequence[j];
            } else {
				if (ctr <= 0 || stack[--ctr] != (sequence[j] == RRB ? LRB : LSB)) {
					isWrong = true;
				}
            }
        }
        isWrong = isWrong || ctr > 0;
        out << (isWrong ? "NO\n" : "YES\n");
    }

    return 0;
}