#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;

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

    int arr[] = {10, 5, 2, 7, 1, 9};
    int n =  sizeof(arr)/sizeof(arr[0]);
    int k = 15;

    cout << lenOfLongSubarr(arr, n, k) << endl;

    return 0;
}