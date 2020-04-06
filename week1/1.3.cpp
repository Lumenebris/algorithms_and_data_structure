#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int i, j, n;
    ifstream fin("input.txt", ios::in);
    fin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (i = 0; i < n; i++)
        fin >> a[i];
    fin.close();
    b[0] = 1;
    for (j = 1; j < n; j++) {
        i = j - 1;
        while ((i > -1) && (a[i] > a[i+1])) {
            swap(a[i], a[i+1]);
            i = i - 1;
        }
        b[j] = i + 2;
    }
    ofstream fout("output.txt", ios::app);
    for (i = 0; i < n; i++)
        fout << b[i] << ' ';
    fout << endl;
    for (i = 0; i < n; i++)
        fout << a[i] << ' ';
    fout.close();
    return 0;
}