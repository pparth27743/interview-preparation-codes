
#include <bits/stdc++.h>
using namespace std;


int solve (string s, int i, int j, int isTrue, vector<vector<vector<int> > > &dp){
    
    if(i>j)
        return 0;
        
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
        
    if(i == j){
        if(isTrue == 1)
            return s[i] == 'T' ? 1 : 0;
        else
            return s[i] == 'F' ? 1 : 0;
    }
    
    int ans = 0;
    
    for(int k=i+1; k<=j-1; k+=2){
        int lt = solve(s, i, k-1, 1, dp);
        int lf = solve(s, i, k-1, 0, dp);
        int rt = solve(s, k+1, j, 1, dp);
        int rf = solve(s, k+1, j, 0, dp);
        
        if(s[k] == '^'){
            if(isTrue == 1)
                ans += (lt*rf) + (lf*rt);
            else
                ans += (lt*rt) + (lf*rf);
        } 
        else if(s[k] == '|'){
            if(isTrue == 1)
                ans += (lt*rt) + (lt*rf) + (lf*rt);
            else
                ans += (lf*rf);
        }
        else if(s[k] == '&'){
            if(isTrue == 1)
                ans += (lt*rt);
            else
                ans += (lt*rf) + (lf*rt) + (lf*rf);
        }
    }
    
    return dp[i][j][isTrue] = ans;
}




int main(){

    string S = "T|F^F&T|F^F^F^T|F^T";

    int n = S.size();
    cout << n << endl;
    vector<vector<vector<int> > > dp(n, vector<vector<int> >(n, vector<int>(2, -1)));
    cout << solve(S, 0, n-1, 1, dp) << endl;

    return 0;   
}  