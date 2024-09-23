// Problem Statement: https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

#include <bits/stdc++.h>
using namespace std;

int minimumSubsetSumDiff(int arr[], int n){
    
    int arrSum = accumulate(arr, arr+n, 0);
    int sum = arrSum/2;
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
        }
    }

    for(int i=sum; i>0; i--){
        if(dp[n][i])
            return arrSum - 2*i;
    }

    return -1;
}

                   
int main(){
   
    
    int arr[] = {1,2,7,10};

    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << minimumSubsetSumDiff(arr, n) << endl;

    return 0;
}
