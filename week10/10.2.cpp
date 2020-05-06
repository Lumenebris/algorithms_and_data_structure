#include <fstream>
#include <vector>
#include <string>
 
using namespace std;

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}

void z_func(string str, vector<int> &z) {
	int a = 0, b = 0;
    for (int i = 1; i < str.length(); i++) {
        z[i] = min(b - i, z[i - a]);
        if (z[i] < 0)
            z[i] = 0;
        while (i + z[i] < str.length() && str[z[i]] == str[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > b) {
            a = i;
            b = z[i] + i;
        }
    }
}
 
int main() {
	string str;
	vector<int> z(1000051, 0);
	
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
    fin >> str;
	
 
    z_func(str, z);
	
    for (int i = 1; i < str.length(); i++)
        fout << z[i] << " ";
    return 0;
}
