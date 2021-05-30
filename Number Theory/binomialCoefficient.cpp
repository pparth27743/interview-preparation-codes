#include <bits/stdc++.h>
using namespace std;



long binomicalCoeff(long n, long k){

    if(k>n)
        return 0;

    if(k==0 || k==n)
        return 1;
    
    // C(n,k) = C(n-1,k) + C(n-1,k-1)
    return binomicalCoeff(n-1, k) + binomicalCoeff(n-1, k-1);
}

// DP solution.
long DPbinomicalCoeff(long n, long k, vector<vector<int> > &dp){

    if(k>n)
        return 0;

    if(k==0 || k==n)
        return 1;

    if(dp[n][k] != -1)
        return dp[n][k];

    // C(n,k) = C(n-1,k) + C(n-1,k-1)
    return dp[n][k] = (DPbinomicalCoeff(n-1, k, dp) + DPbinomicalCoeff(n-1, k-1, dp));
}



int main(){

    int n = 35;
    int k = 22;

    vector<vector<int> > dp(n+1, vector<int>(k+1, -1));
   
    cout << DPbinomicalCoeff(n,k,dp) << endl;

    return 0;
}
