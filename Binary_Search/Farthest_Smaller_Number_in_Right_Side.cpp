
/*
Problem Statement:
Given an array arr[] of size N. For every element in the array, the task is to find the index of the farthest element in the array to the right which is smaller than the current element. If no such number exists then print -1. 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N ,int arr[]){
    
    vector<int> suffix_min(N);
    vector<int>  ans(N);
    
    int minel = INT_MAX;
    for(int i=N-1; i>=0; i--){
        minel = min(minel, arr[i]);
        suffix_min[i] = minel;
    }
    
    for(int i=0; i<N; i++){
        int res = -1;
        int low=i+1,high=N-1, mid;
        
        while(low <= high){
            mid = (low+high)/2;
            if(arr[i] > suffix_min[mid]){
                res = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        ans[i] = res;
    }

    return ans;
}

int main()
{
    int arr[] = {7,7,8,9,1,2,3,4,5,6};

    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans;
    ans = solve(n, arr);

    for(int i : ans)
        cout << i << " ";

    cout << endl;
    

    return 0;
}  