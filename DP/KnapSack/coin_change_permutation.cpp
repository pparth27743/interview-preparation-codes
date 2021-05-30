#include <bits/stdc++.h>
using namespace std;

int coinChage_Permutation(int coins[], int n, int sum){

    int dp[sum+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int j=1; j<=sum; j++){
        for(int i=1; i<=n; i++){
            if(coins[i-1]<=j)
                dp[j] = dp[j] + dp[j-coins[i-1]];
        }
    }

    return dp[sum];
}


   
int main(){
   
    int val[] = {1,2,3,4,5,6};

    int n = sizeof(val)/sizeof(val[0]);
    cout << coinChage_Permutation(val, n, 10) << endl; 
    

    return 0;
}


