#include <bits/stdc++.h>
using namespace std;


int count_unique_substrings

(string s){

    int n = s.size();
    long long p = 31;
    long long m = 1e9+9;

    vector<long long> p_pow(n);
    vector<long long> prefix_hash(n+1,0);

    p_pow[0] = 1;

    // calculate the power of p in advance
    for(int i=1; i<n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    // calculate the hash of prefix of string s.
    for(int i=0; i<n; i++)
        prefix_hash[i+1] = (prefix_hash[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    
    int cnt = 0;

    for(int l=1; l<=n; l++){
        set<long long> hs;
        for(int i=0; i<=n-l; i++){
            long long hcurr;
            hcurr = (prefix_hash[i+l] + m - prefix_hash[i]) % m;
            hcurr = (hcurr * p_pow[n-1-i]) % m;
            hs.insert(hcurr);
        }
        cnt += hs.size();
    }

    return cnt;
}



int main(){

    vector<int> ans;

   
    cout << count_unique_substrings("abc") << endl;

    return 0;
}

