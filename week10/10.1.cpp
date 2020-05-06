#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "edx-io.hpp"
#define fin io
#define fout io

vector<int> prefix(string str) {
	vector<int> res;
	res.push_back(0);
	for (int i = 1; i < str.length(); i++) {
		int k = res[i - 1];
		while (k > 0 && str[i] != str[k])
			k = res[k - 1];
		if (str[i] == str[k])
			k++;
		res.push_back(k);
	}
	return res;
}

int main() {
	string str;
	fin >> str;
	vector<int> res = prefix(str);
	for (int i = 0; i < res.size(); i++) {
		fout << res[i] << " ";
	}
	return 0;
}
