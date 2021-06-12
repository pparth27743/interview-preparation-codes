#include <bits/stdc++.h>
using namespace std;

// O(2^nk)
long binomicalCoeff(long n, long k){

    if(k>n)
        return 0;

    if(k==0 || k==n)
        return 1;

    // C(n,k) = C(n-1,k) + C(n-1,k-1)
    return binomicalCoeff(n-1, k) + binomicalCoeff(n-1, k-1);
}

// DP solution. O(n*k)
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



// It generates Pascal's Triangle.
vector<vector<int> > Tabular_binomicalCoeff(long n){

    vector<vector<int> > dp(n+1, vector<int> (n+1, 0));

    for(int i=0; i<=n; i++)
        dp[i][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    
   return dp;
}


int main(){

    int n = 6;
    int k = 3;

    // vector<vector<int> > dp(n+1, vector<int>(k+1, -1));
    // cout << DPbinomicalCoeff(n,k,dp) << endl;
    
    vector<vector<int> > dp = Tabular_binomicalCoeff(n);

     for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
   

    return 0;
}
