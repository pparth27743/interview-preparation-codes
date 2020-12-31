#include <bits/stdc++.h>
using namespace std;


int countSubsetSum(int arr[], int n, int sum){

    int dp[n+1][sum+1];

    for(int i=0; i<=n; i++)
        dp[i][0] = 1;

    for(int j=1; j<=sum; j++)
        dp[0][j] = 0; 
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}


int count_subset_with_given_difference(int arr[], int n, int diff){

    int arrSum = accumulate(arr, arr+n, 0);
    int sum = (diff+arrSum)/2;

    if((diff+arrSum)&1)
        return 0;

    return countSubsetSum(arr, n, sum);
}

int main(){
   
    
    int arr[] = {1,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int diff = 1;
    
    cout << count_subset_with_given_difference(arr, n, diff) << endl;

    return 0;
}
