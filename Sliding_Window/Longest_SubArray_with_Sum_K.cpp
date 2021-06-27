#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;

// This works for only for +ve intergers 

int solve(int arr[], int n, int k){

    int i=0, j=0, ans=0;
    int sum = 0;

    while(j<n){
        sum += arr[j];

        if(sum < k)
            j++;
        else if(sum == k){
            ans = max(ans, j-i+1);
            j++;
        }
        else{
            while(sum > k){
                sum -= arr[i];
                i++;
            }

            // We have to check whether sum == k after removing some element from the tail of window.
            if(sum == k)
                ans = max(ans, j-i+1);

            j++;
        }
    }
    
    return ans;
}

// This works for all the interges 
int lenOfLongSubarr(int arr[],  int n, int k){ 
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        long sum = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
        
            if(mp.find(sum - k) != mp.end()){
                ans = max(ans, i-mp[sum-k]);
            }
            
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return ans;
    } 

int main() {

    int arr[] = {10, 5, 1, 1, 9, 2, 9, 10, 5, 7, 5, 10, 2, 7, 7, 1, 2, 9};
    int n =  sizeof(arr)/sizeof(arr[0]);
    int k = 15;

    cout << lenOfLongSubarr(arr, n, k) << endl;
    cout << solve(arr, n, k) << endl;

    return 0;
}