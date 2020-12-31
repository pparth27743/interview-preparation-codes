#include <bits/stdc++.h>
using namespace std;


// 1D implementation
int un_knapsack_1D(int wt[], int val[], int W, int n){

    vector<int> dp(W+1, 0);
    // dp[0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(wt[i-1]<=j)
                dp[j] = max(dp[j], val[i-1] + dp[j-wt[i-1]]);
        }
    }

    return dp[W];
}

// 2D implementation
int un_knapsack_2D(int wt[], int val[], int W, int n){

    int dp[n+1][W+1];

    for(int i=0; i<=n; i++)
        dp[i][0] = 0;

    for(int j=1; j<=W; j++)
        dp[0][j] = 0;


    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(wt[i-1]<=j)
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}

   
int main(){
   
    int wt[] = {1, 3, 4, 5, 9, 11};
    int val[] = {10, 40, 50, 70, 110, 130};
    
    int n = 6;
    int W = 30;
    
    cout << un_knapsack_2D(wt, val, W, n) << endl; 
    cout << un_knapsack_1D(wt, val, W, n) << endl; 


    return 0;
}
