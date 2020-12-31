#include <bits/stdc++.h>
using namespace std;

int coinChage_1D(int coins[], int n, int sum){

    int dp[sum+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(coins[i-1]<=j)
                dp[j] = dp[j] + dp[j-coins[i-1]];
        }
    }

    return dp[sum];
}


int coinChage_2D(int coins[], int n, int sum){


    int dp[n+1][sum+1];

    for(int i=0; i<=n; i++)
        dp[i][0] = 1;

    for(int j=1; j<=sum; j++)
        dp[0][j] = 0;


    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(coins[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }


    return dp[n][sum];
}

   
int main(){
   
    int val[] = {1, 5, 8, 9, 10, 17, 20};
    

    int n = sizeof(val)/sizeof(val[0]);

    cout << coinChage_1D(val, n, 235) << endl; 
    cout << coinChage_2D(val, n, 235) << endl; 


    return 0;
}
