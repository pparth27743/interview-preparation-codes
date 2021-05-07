#include <bits/stdc++.h>
using namespace std;


// 1D approach
int subsetSum_1D(int arr[], int n, int sum){

    vector<int> dp(sum+1, 0);

    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=sum; j>=arr[i]; j--){
            dp[j] += dp[j-arr[i]];
        }
    }
    return dp[sum];
}



// 1D (2 rows) approach
int subsetSum_1D_2_rows(int arr[], int n, int sum){

    int dp[2][sum+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;

    int r=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j)
                dp[1-r][j] = dp[r][j] + dp[r][j-arr[i-1]];
            else
                dp[1-r][j] = dp[r][j];   
        }
        r = 1-r;
    }

    return dp[r][sum];
}


void display(vector<int> v){
    for(int i : v)
        cout << i << " ";
    cout << endl;
}

// Print subsets 
void printsubsets(int arr[], int i, int sum, vector<vector<int> > dp, vector<int> &v){

    if(sum == 0){
        display(v);
        return;
    }
    
    // Exclude current element
    if(dp[i-1][sum] != 0){
        vector<int> p = v;
        printsubsets(arr, i-1, sum, dp, p);
    }

    // Include current element
    if(sum >= arr[i-1] && dp[i-1][sum - arr[i-1]] !=0){
        v.push_back(arr[i-1]);
        printsubsets(arr, i-1, sum-arr[i-1], dp, v);
    }
}


// 2D approach
int subsetSum_2D(int arr[], int n, int sum){

    vector<vector<int> > dp(n+1, vector<int>(sum+1, 0));

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

    if(dp[n][sum]){
        vector<int> v;
        printsubsets(arr, n, sum, dp, v);
    }

    return dp[n][sum];
}

                   
int main(){
   
    int arr[] = {1,3,5,5,10,5,7,12,10,22,43,65,3,3,35,6,7,9,12,22,23,20,16};

    int n = sizeof(arr)/sizeof(arr[0]);
    
    int sum;
    cin >> sum;

    cout << subsetSum_2D(arr, n, sum) << endl; 
    // cout << subsetSum_1D_2_rows(arr, n, sum) << endl; 
    // cout << subsetSum_1D(arr, n, sum) << endl; 


    return 0;
}
