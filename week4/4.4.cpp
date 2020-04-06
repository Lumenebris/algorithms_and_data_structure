#include <iostream>
#include <string>
#include <deque>
#include <queue>

using namespace std;

#include "edx-io.hpp"
#define in io
#define out io

int main() {
    char c;
    queue<long> queue;
    deque<long> deque;
	long digit;
    int n;
	
    in >> n;

    for (int i = 0; i < n; i++) {
        in >> c;
		
		switch (c) 
		{
			case '+':
				in >> digit;
				queue.push(digit);
				while (!deque.empty() && deque.back() > digit) {
					deque.pop_back();
				}
				deque.push_back(digit);
				break;
			
			case '-': 
				if (deque.front() == queue.front()) {
					deque.pop_front();
				}
				queue.pop();
				break;
			
			case '?':
				out << deque.front() << '\n';
				break;
		}
    }

    return 0;
}