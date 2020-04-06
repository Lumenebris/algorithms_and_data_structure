#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, i, j;
    ifstream fin("input.txt", ios::in);
    fin >> n;
    double *a = new double[n];
    int *b = new int[n];
    for (i = 0; i < n; i++) {
        fin >> a[i];
        b[i] = i+1;
    }
    fin.close();
    for (j = 1; j < n; j++) {
        i = j - 1;
        while ((i > -1) && (a[i] > a[i+1])) {
            swap(a[i], a[i+1]);
            swap(b[i], b[i+1]);
            i = i - 1;
        }
    }
    ofstream fout("output.txt", ios::app);
    fout << b[0] << ' ' <<  b[n/2] << ' ' << b[n-1];
    fout.close();
    return 0;
}