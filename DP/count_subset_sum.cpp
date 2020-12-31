#include <bits/stdc++.h>
using namespace std;

int subsetSum(int arr[], int n, int sum){

    int dp[n+1][sum+1];

    for(int i=0; i<=n; i++)
        dp[i][0] = 1;

    for(int j=1; j<=sum; j++)
        dp[0][j] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];

            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }

    return dp[n][sum];
}

                   
int main(){
   
    int arr[] = {1,3,5,7,12,10,22,43,65};

    int n = sizeof(arr)/sizeof(arr[0]);

    int sum;
    cin >> sum;

    cout << subsetSum(arr, n, sum) << endl; 


    return 0;
}
