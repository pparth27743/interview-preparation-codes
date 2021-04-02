#include <bits/stdc++.h>
using namespace std;

/*
    Pattern finding algorithm.
    return all the indices where the pattern start to match in the orginal stirng/text;
*/


vector<int> Rabin_Karp(string A, string pattern){

    int n = A.size();
    int p = 31;
    int m = 1e9+9;

    vector<int> ans;

    vector<long long> p_pow(n,0);
    for(int i=1; i<n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;


    long long p_hash = 0;
    for(int i=0; i<pattern.size(); i++){
        p_hash = (p_hash + (pattern[i]- 'a' + 1) * p_pow[i]) % m;
    }


    vector<long long> prefix_hash(n+1, 0);
    for(int i=0; i<n; i++)
        prefix_hash[i+1] = (prefix_hash[i] + (A[i] - 'a' + 1)*p_pow[i]) % m;

    int l = pattern.size();

    for(int i=0; i<=n-l; i++){
        int curr_h;
        curr_h = (prefix_hash[i+l] + m - prefix_hash[i]) % m;
        curr_h = (curr_h * p_pow[n-1-i]) % m;
        if(curr_h == p_hash){
            bool flag = true;
            for(int k=i, j=0; k-i<l; k++,j++){
                if(A[k] != pattern[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(i);
        }
    }

    return ans;
}

int main(){
   

    vector<int> ans;

    ans = Rabin_Karp("Parth Patel Parth Patel Parth Part P arth arthhh", "arth");

    for(int i : ans){
        cout << i << endl;
    }

    return 0;
}