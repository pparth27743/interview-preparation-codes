
#include <bits/stdc++.h>
using namespace std;

// O(e * f^2)
int solve(int e, int f, vector<vector<int> > &dp){
    
    if(f <= 1 || e == 1)
        return f;
        
    if(dp[e][f] != -1)
        return dp[e][f];
        
    int ans = INT_MAX, temp, s1,s2;
        
    for(int k=1; k<=f; k++){
        
        s1 = solve(e-1, k-1, dp);
        s2 = solve(e, f-k, dp);
        
        temp = 1 + max(s1, s2);
        ans = min(ans, temp);
    }
    
    return dp[e][f] = ans;
}


// O(e * f log f)
int solve(int e, int f, vector<vector<int> > &dp){

    if(e == 1 || f <= 1)
        return f;
        
    if(dp[e][f] != -1)
        return dp[e][f];
        
    int ans = INT_MAX;
    
    int low = 1, high = f, mid;
    
    while(low <= high){
        
        mid = low + (high - low)/2;
        
        int t1 = 1 + solve(e-1, mid-1, dp);
        int t2 = 1 + solve(e, f-mid, dp);
    
        if(t1 < t2)
            low = mid+1;
        else
            high = mid-1;
        
        ans = min(ans, max(t1, t2));
    }
    
    return dp[e][f] = ans;
}


int main(){

    int A = 7, B = 10000;

    vector<vector<int> > dp(A+1, vector<int>(B+1, -1));
    cout << solve(A,B, dp) << endl;
    
    
    return 0;   
}  