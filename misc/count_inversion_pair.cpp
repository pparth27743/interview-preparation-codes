#include <bits/stdc++.h>
using namespace std;

long long int merge(long long int arr[], long long int l, long long int m, long long int r){
    
    long long int l1 = m-l+1, l2=r-m;
    long long int arr1[l1], arr2[l2];
    
    for(long long int i=0; i<l1; i++)
        arr1[i] = arr[l+i];
    
    for(long long int i=0; i<l2; i++)
        arr2[i] = arr[m+1+i];
        
        
    long long int k=l, i=0, j=0;
    long long int inv = 0;
    
    while(i<l1 && j<l2){
        if(arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else{
            arr[k++] = arr2[j++];
            inv += l1-i;
        }
    }
    
    while(i<l1)
        arr[k++] = arr1[i++];
    
    while(j<l2)
        arr[k++] = arr2[j++];
        
    return inv;
}

long long int mergesort(long long arr[], long long int l, long long int r){
    long long int inv = 0;
    if(l < r){
        int mid = l + (r-l)/2;
        inv += mergesort(arr, l, mid);
        inv += mergesort(arr, mid+1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}

long long int inversionCount(long long int arr[], long long int N)
{
    return mergesort(arr, 0, N-1);
}


int main(){

    long long int arr[] = {5, 4, 3, 2, 1};
    long long int n = sizeof(arr)/sizeof(arr[0]);

    cout << inversionCount(arr, n);
   
    return 0;
}