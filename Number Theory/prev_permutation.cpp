#include <bits/stdc++.h>
using namespace std;

 void prevPermutation(vector<int>& nums) {

    int n = nums.size();
    int k, l;
    for(k=n-2; k>=0; k--){
        if(nums[k] > nums[k+1])
            break;    
    }

    if(k<0){
        reverse(nums.begin(), nums.end());
        return;
    }

    for(l=k+1; l<n; l++){
        if(nums[k] > nums[l])
            break;
    }

    swap(nums[k], nums[l]);

    reverse(nums.begin() + k + 1, nums.end());
}


int main(){

    int arr[] = {2,1,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> v(begin(arr), end(arr));

    prevPermutation(v);

    for(int num : v)
        cout << num <<  " ";
    cout << endl;

    
    return 0;
}
