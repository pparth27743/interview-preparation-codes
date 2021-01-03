#include <bits/stdc++.h>
using namespace std;



int recursive(int coins[], int n, int sum){
    
    if(sum == 0) 
        return 0;
    
    else if(n < 0)
        return INT_MAX-1;
    
    else{
        if(coins[n] <= sum)
            return min(recursive(coins, n-1, sum), 1 + recursive(coins, n, sum-coins[n]));
        else
        return recursive(coins, n-1, sum);
    }
}

int min_coinChage_1D(int coins[], int n, int sum){

    vector<int> dp(sum+1, INT_MAX-1);
    dp[0] = 0;

    for(int i=0; i<n; i++){
        for(int j=1; j<=sum; j++){
            if(coins[i] <= j)
                dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
        }
    }

    return dp[sum];
}


int min_coinChage_2D(int coins[], int n, int sum){

    int dp[n+1][sum+1];

    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
   
    for(int j=1; j<=sum; j++)
        dp[0][j] = INT_MAX-1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(coins[i-1] <= j)
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
            
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    return dp[n][sum];
}

   
int main(){
   
    int val[] = {2, 6, 5, 9};
    

    int n = sizeof(val)/sizeof(val[0]);
    
    int sum = 1420;

    cout << min_coinChage_2D(val, n, sum) << endl; 
    cout << min_coinChage_1D(val, n, sum) << endl; 
    cout << recursive(val, n-1, sum) << endl; 


    return 0;
}
