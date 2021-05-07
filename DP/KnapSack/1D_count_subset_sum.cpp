#include <bits/stdc++.h>
using namespace std;

int subsetSum(int arr[], int n, int sum){

    vector<int> dp(sum+1, 0);

    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=sum; j>=arr[i]; j--){
            dp[j] += dp[j-arr[i]];
        }
    }
    return dp[sum];
}

                   
int main(){
   
    int arr[] = {1,3,5,7,12,10,22,43,65};

    int n = sizeof(arr)/sizeof(arr[0]);

    int sum;
    cin >> sum;

    cout << subsetSum(arr, n, sum) << endl; 


    return 0;
}
