#include <bits/stdc++.h>
using namespace std;


int bs(int arr[], int l, int r, int key){

    if(l<=r){
        int m = (l+r)/2;
        if(arr[m] == key)
            return m;
        else if(arr[m] > key)
            return bs(arr,l,m-1,key);
        else
            return bs(arr,m+1,r,key);
    }else{
        return -1;
    }
    return 0;
}
      
int main(){
    
    int arr[] = {-3, 2, 1, -2, 4, -6, 10, -5, 20, 32};
    int size = sizeof(arr)/sizeof(arr[0]);

    int ind = bs(arr, 0, size-1, 00);

    cout << ind << endl;


    return 0;
}