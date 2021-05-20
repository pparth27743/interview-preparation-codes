
#include <bits/stdc++.h>
using namespace std;


bool solve(string a, string b, unordered_map<string, bool> &dp){
    
    if(a == b)
        return true;
    
    if(a.size() == 1)
        return false;
        
    string key = "";
    key.append(a);
    key.push_back('$');
    key.append(b);
    
    if(dp.find(key) != dp.end())    
        return dp[key];
        
    bool ans = false;
    int n = a.size();
    
    for(int k=1; k<n; k++){
        bool c1 = solve(a.substr(0,k), b.substr(0,k), dp) && solve(a.substr(k, n-k), b.substr(k, n-k), dp);
        bool c2 = solve(a.substr(0,k), b.substr(n-k,k), dp) && solve(a.substr(k, n-k), b.substr(0, n-k), dp);
        if(c1 || c2){
            ans = true;
            break;
        }
    }
    return dp[key] = ans;
}



int main(){

    string a = "great";
    string b = "rgate";

    if(a.size() != b.size()){
        cout << "0" << endl;
    }
    else{
        unordered_map<string, bool> dp;
        cout << solve(a,b, dp) << endl;
    }
    
    return 0;   
}  