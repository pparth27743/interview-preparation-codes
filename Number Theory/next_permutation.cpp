#include <bits/stdc++.h>
using namespace std;

/*
            Solution Approach.

According to Wikipedia, a man named Narayana Pandita presented the following simple algorithm to solve this problem in the 14th century.

Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
Find the largest index l > k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array nums[k + 1:].
*/


 void nextPermutation(vector<int>& nums) {

    int n = nums.size();
    int k, l;
    for(k=n-2; k>=0; k--){
        if(nums[k] < nums[k+1])
            break;    
    }

    if(k<0){
        reverse(nums.begin(), nums.end());
        return;
    }

    for(l=n-1; l>k; l--){
        if(nums[k] < nums[l])
            break;
    }

    swap(nums[k], nums[l]);

    reverse(nums.begin() + k + 1, nums.end());
}


int main(){

    // int arr[] = {1,9,4,6,7};
    int arr[] = {1, 7, 9, 6, 4};
    
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> v(begin(arr), end(arr));

    nextPermutation(v);

    for(int num : v)
        cout << num <<  " ";
    cout << endl;

    
    return 0;
}
