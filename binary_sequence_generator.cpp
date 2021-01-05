#include <bits/stdc++.h>
using namespace std;


int main(){

    int n = 3;

    // int nthBit = 1<<n;

    for(int i=0; i<pow(2,n); i++){
        // string str = bitset<8>(nthBit | i).to_string();
        string str = bitset<8>(i).to_string();
        cout << str.substr(str.size() - n) << endl;
    }

    return 0;
}