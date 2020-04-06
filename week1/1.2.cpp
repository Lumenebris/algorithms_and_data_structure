#include <fstream>
using namespace std;

int main()
{
    long long a, b, res;
	ifstream fin("input.txt");
	fin >> a >> b;
 	fin.close();
    ofstream fout("output.txt");
    fout << (a + b*b);
    fout.close();
    return 0;
}