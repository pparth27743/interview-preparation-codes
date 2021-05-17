#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/printing-matrix-chain-multiplication-a-space-optimized-solution/


long mcmTab(int arr[], int n){

    vector<vector<long> > dp(n, vector<long> (n, 0));

    for(int l=2; l<=n-1; l++){                          // l = 2 -> n-1
        for(int i=1; i<=n-l; i++){                      // i = 1 -> n-L
            int j = i + l - 1;                          // j = i+L-1
            dp[i][j] = LONG_MAX;
            for(int k = i; k<=j-1; k++){
                long tmp = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                if(tmp < dp[i][j]){
                    dp[i][j] = tmp;
                }
            }
        }
    }
    return dp[1][n-1];
}


long mcm(int arr[], int i, int j, vector<vector<long> > dp){

    if(i>=j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    long ans = LONG_MAX;
    for(int k=i; k<=j-1; k++){
        long tmp = mcm(arr, i, k, dp) + mcm(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, tmp);
    }
    return dp[i][j] = ans;
}


int main()
{

    int arr[] = {12,22,11,42,63,68,34,12,34,65}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<vector<long> > dp(n+1, vector<long> (n+1, -1));

    cout << mcm(arr, 1, n-1, dp) << endl;
    cout << mcmTab(arr, n) << endl;
    return 0;
}
