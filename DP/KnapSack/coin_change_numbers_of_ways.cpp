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


void display(vector<int> v){
    for(int i : v)
        cout << i << " ";
    cout << endl;
}

void printSubset(int coins[], int i, int target, vector<vector<int> > dp, vector<int> &v) {
    
    if(target == 0){
        display(v);
        return;
    }

    // exclude current coin
    if(dp[i-1][target]){
        vector<int> p = v;
        printSubset(coins, i-1, target, dp, p);
    }

    // include current coin
    if(target >= coins[i-1] && dp[i][target-coins[i-1]]){
        v.push_back(coins[i-1]);
        printSubset(coins, i, target-coins[i-1], dp, v);
    }
}

int coinChage_2D(int coins[], int n, int sum){
   
    vector<vector<int> > dp(n+1, vector<int>(sum+1, 0));

    for(int i=0; i<=n; i++)
        dp[i][0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(coins[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    vector<int> v;
    printSubset(coins, n, sum, dp, v);

    return dp[n][sum];
}

   
int main(){
   
    int val[] = {1, 5, 8, 9, 10, 17, 20};
    
    int n = sizeof(val)/sizeof(val[0]);

    int target = 20;

    // cout << coinChage_1D(val, n, target) << endl; 
    cout << coinChage_2D(val, n, target) << endl; 


    return 0;
}
