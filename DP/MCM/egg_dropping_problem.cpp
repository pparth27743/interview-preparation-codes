
#include <bits/stdc++.h>
using namespace std;


int solve(int e, int f, vector<vector<int> > &dp){
    
    if(f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;
        
    if(dp[e][f] != -1)
        return dp[e][f];
        
    int ans = INT_MAX, temp;
        
    for(int k=1; k<=f; k++){
        
        int s1,s2;
        
        if(dp[e-1][k-1] != -1)
            s1 = dp[e-1][k-1];
        else
            s1 = dp[e-1][k-1] = solve(e-1, k-1, dp);
            
        if(dp[e][f-k] != -1)
            s2 = dp[e][f-k];
        else
            s2 = dp[e][f-k] = solve(e, f-k, dp);
        
        temp = 1 + max(s1, s2);
        ans = min(ans, temp);
    }
    
    return dp[e][f] = ans;
}




int main(){

    int A = 7, B = 10000;

    vector<vector<int> > dp(A+1, vector<int>(B+1, -1));
    cout << solve(A,B, dp) << endl;
    
    
    return 0;   
}  