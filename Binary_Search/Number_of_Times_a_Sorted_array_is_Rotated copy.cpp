#include <bits/stdc++.h>
using namespace std;


// We need to find out number of time sorted array is right rotated. 

int solve(int arr[], int n){

    int l=0, r=n-1, m, ans=0;

    while(l <= r){
        m = l + (r-l)/2;
        //      arr[m] <= next    but arr[m] < prev
        if(arr[m] <= arr[(m+1)%n] && arr[m] < arr[(m+n-1)%n]){
            ans = m;    
            break;
        } 
        else if(arr[m] <= arr[r]){
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    return ans;
}
   
int main(){
   
    int val[] = {7,7,8,9,1,2,3,4,5,6};

    int n = sizeof(val)/sizeof(val[0]);
    int ans = solve(val, n);

    cout << ans << endl;

    return 0;
}


