#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    int a, b, res;
	ifstream fin("input.txt");
	fin >> a >> b;
 	fin.close();
    ofstream fout("output.txt");
    fout << (a + b);
    fout.close();
    return 0;
}