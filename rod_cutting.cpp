#include <bits/stdc++.h>
using namespace std;

int cutRod_1D(int val[], int cut[], int n, int length){

    int dp[length+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=length; j++){
            if(cut[i-1]<=j)
                dp[j] = max(dp[j], val[i-1] + dp[j-cut[i-1]]);
        }
    }

    return dp[length];
}


int cutRod_2D(int val[], int cut[], int n, int length){

    int dp[n+1][length+1];

    for(int i=0; i<=n; i++)
        dp[i][0] = 0;

    for(int j=1; j<=length; j++)
        dp[0][j] = 0;


    for(int i=1; i<=n; i++){
        for(int j=1; j<=length; j++){
            if(cut[i-1]<=j)
                dp[i][j] = max(val[i-1] + dp[i][j-cut[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][length];
}

   
int main(){
   
    int val[] = {1, 5, 8, 9, 10, 17, 17, 20};

    int n = sizeof(val)/sizeof(val[0]);

    int len[n];
    for(int i=0; i<n; i++)
        len[i] = i+1;

    cout << cutRod_2D(val, len, n, 8) << endl; 
    cout << cutRod_1D(val, len, n, 8) << endl; 


    return 0;
}
