#include <bits/stdc++.h>
using namespace std;

/*
    Pattern finding algorithm.
    return all the indices where the pattern start to match in the orginal stirng/text;
*/


// This is the function from CP algorithm.
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) {
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++){
        h[i+1] = (h[i] + (t[i]) * p_pow[i]) % m; 
    }

    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i]) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}


vector<int> Rabin_Karp(string A, string pattern){

    int n = A.size();
    int p = 31;
    int m = 1e9+9;

    vector<int> ans;

    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for(int i=1; i<n; i++){
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    long long p_hash = 0;
    for(int i=0; i<pattern.size(); i++){
        p_hash = (p_hash + (pattern[i]) * p_pow[i]) % m;
    }

    vector<long long> prefix_hash(n+1, 0);
    for(int i=0; i<n; i++){
        prefix_hash[i+1] = (prefix_hash[i] + (A[i])*p_pow[i]) % m;
    }

    int l = pattern.size();

    for(int i=0; i<=n-l; i++){
        long long curr_h;
        curr_h = (prefix_hash[i+l] + m - prefix_hash[i]) % m;
        if(curr_h == (p_hash * p_pow[i])%m){
            if(A.substr(i,l) == pattern)
                ans.push_back(i);
        }
    }

    return ans;
}


int main(){
   
    vector<int> ans;

    // ans = Rabin_Karp("Parth Patel Parth Patel Parth Part P arth arthhh", "arth");
    ans = solve("Parth Parth", "arth");
    // ans = rabin_karp("arth","Parth Parth");

    for(int i : ans){
        cout << i << endl;
    }

    return 0;
}