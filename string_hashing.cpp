#include <bits/stdc++.h>
using namespace std;

long long hashing(string s){
    
    long long p = 31;
    long long m = 1e9 + 7;
    long long hash_val = 0;
    long long p_pow = 1;
    for(char ch : s){
        hash_val += ((ch - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }

    return hash_val;
}

int main(){

    cout << hashing("parth") << endl;

}
