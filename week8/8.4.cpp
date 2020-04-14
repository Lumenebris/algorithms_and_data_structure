#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <cmath>
#include <map>
#include <set>

using namespace std;

ofstream fout("output.txt", ios::binary);
ifstream fin("input.txt", ios::binary);



string answer[10];
int hashOf(std::string s, int multiple) {
    int rv = 0;
    for (int i = 0; i < s.length(); ++i) {
        rv = multiple * rv + s[i];
    }
    return rv;
}

void bitv(int x)   
{  
    int i, b;  
    long c = 0;  
    for(i = 0; x > 0; i++)  
    {
        b = x % 2;  
        x = (x - b)/2;
        c += b * pow(10, i);
    }
}   


int main() {
    const int Q = 11;
    const int N = 1 << Q;
    int m2 = 5;
    int m1 = 7;
    std::map<int, int> d;
    int n;
    fin >> n;
    string s = "";
    vector<pair<int,int>> ans;
    set<string> uniq;
        s = "";
        for (int i = 0; i <= N; i++) {
            bitset<32> bits(i);
            s += 'a' + (bits.count()) % 2;
        }

        for (int i = 0; i < N; i += 16) {
            for (int j = 0; i + j <= N; j += 16) {
                string temp = s.substr(i, j);
                if (uniq.count(temp))
                    continue;
                int hash = hashOf(temp,m1);
                if (hash == -1608748800 )
                    ans.push_back(make_pair(i, j));
                if (d.count(hash)) {
                    d[hash]++;
                } else {
                    d[hash] = 1;
                }
                uniq.insert(temp);
            }
        }

    set<pair<int,int>> temp;
    for (auto key : ans) {
        temp.insert(key);
    }

    for(int i = 2; i < 1024; i++){
        int hash = hashOf(s.substr(temp.begin()->first,temp.begin()->second),i);
        for(auto key : temp){
            if(hash != hashOf(s.substr(key.first,key.second),i))
                temp.erase(key);
        }
    }

    int count = 0;
    for (auto key1 : temp) {
        for (auto key2 : temp) {
            for (auto key3 : temp) {
                for (auto key4 : temp) {
                    for (auto key5 : temp) {
                        for (auto key6 : temp) {
                            if(count >= n)
                                break;
                            fout << s.substr(key1.first,key1.second)
                                 << s.substr(key2.first,key2.second)
                                 << s.substr(key3.first,key3.second)
                                 << s.substr(key4.first,key4.second)
                                 << s.substr(key5.first,key5.second)
                                 << s.substr(key6.first,key6.second)<<"\n";
                            count++;
                        }
                        if(count >= n)
                            break;
                    }
                    if(count >= n)
                        break;
                }
                if(count >= n)
                    break;
            }
            if(count >= n)
                break;
        }
        if(count >= n)
            break;
    }


    fin.close();
    fout.close();

    return 0;
}