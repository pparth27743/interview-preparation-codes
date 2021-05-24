#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[] = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 };

    int n = sizeof(arr)/sizeof(arr[0]);

    int dp[n];
    copy(arr, arr+n, dp);

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], arr[i] + dp[j]);
            }
        }
    }
    
    int ans = INT_MIN;

    for(int i=1; i<n; i++){
        if(ans < dp[i])
            ans = dp[i];   
    }
    
    cout << ans << endl;

    return 0; 

}

