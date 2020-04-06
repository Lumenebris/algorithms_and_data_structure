#include <iostream>
#include <fstream>
 
using namespace std;
#define maxn 100000
 
int main()
{
    //int a[maxn];
    int n, i, j;
	long long k = 0;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n;
    int *a = new int[n];
    
    // Заполняем элементы массива
    for (i = 0; i < n; i++)
        fin >> a[i];
        
    fin.close();
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                k++;
            }
        }
    }
    fout << k;
    fout.close();
    return 0;
}